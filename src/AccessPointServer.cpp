#include "AccessPointServer.h"

// Load Wi-Fi library
#include <WiFi.h>

// Replace with your network credentials
const char* apName = "ESP32-Access-Point";
const char* pass = "123456789";

// Set web server port number to 80
WiFiServer server(80);

// Variable to store the HTTP request
String header;

// Auxiliar variables to store the current output state
String output26State = "off";
String output27State = "off";

// Assign output variables to GPIO pins
const int output26 = 26;
const int output27 = 27;

String inputNetName = "";
String inputPAss = "";

bool isConnected = false;
bool isConnecting = false;

AccessPointServer::AccessPointServer(){};

void AccessPointServer::setup() {
  // Connect to Wi-Fi network with SSID and pass
  Serial.print("Setting AP (Access Point)…");
  // Remove the pass parameter, if you want the AP (Access Point) to be open
  WiFi.softAP(apName, pass);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

  server.begin();
}

void AccessPointServer::checkServer(){
  WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            if (header.indexOf("GET /credentials?") >= 0 && header.indexOf("?networkName=") >= 0 && header.indexOf("password=") >= 0) {
              // Get networkName string
              int startNetName = header.indexOf("networkName=") + 12;
              int endNetName = header.indexOf("&");
              // Get pass string
              int startPassName = header.indexOf("password=") + 9;
              // int endPassName = header.substring(header.indexOf("&"));

              Serial.println(header.substring(startPassName, header.length()));
            }

            // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons
            // Feel free to change the background-color and font-size attributes to fit your preferences
            client.println("<style>html { color: white; background-color: black; font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #4CAF50; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #555555;}</style></head>");
            // Web Page Heading
            client.println("<body><h1>ESP32 Web Server</h1>");

            // if(isConnected) {
            //   // Is connected
            //   client.println("<h3>Ingrese las credenciales para conectar a una red wifi.</h3>");
            // } else if(isConnecting) {
            //   // Is connecting
            //   client.println("<h3>Ingrese las credenciales para conectar a una red wifi.</h3>");
            // } else {
            //   // Is not connected
              client.println("<h3>Ingrese las credenciales para conectar a una red wifi.</h3>");
              client.println("<form action=\"/credentials\">");
              client.println("Nombre de red:<br>");
              client.println("<input type=\"text\" name=\"networkName\" value=\"Red\">");
              client.println("<br>Password:<br><input type=\"text\" name=\"password\" value=\"Pass\">");
              client.println("<br><br><input type=\"submit\" value=\"Submit\"></form>");
            client.println("</body></html>");

            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
