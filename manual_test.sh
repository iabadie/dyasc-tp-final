cd ..
cd test-baliza/

mv src/test/java/ar/edu/untref/dyasc/broke src/test/java/ar/edu/untref/dyasc/Broke.java

git add .
git commit -m "Test fail"
git push origin HEAD

sleep 5m

git reset HEAD~1
git checkout .
git push origin HEAD -f

cd ..
cd BalizaIntegracionContinua
