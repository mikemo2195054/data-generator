echo Please input problem name.
read probname

mkdir userdata/$probname
cp templates/* userdata/$probname/

cd userdata/$probname/