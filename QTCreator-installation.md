//QT CREATOR INSTALLATION
wget https://download.qt.io/archive/qt/5.12/5.12.11/qt-opensource-linux-x64-5.12.11.run
sudo chmod +x qt-opensource-linux-x64-5.12.11.run
sudo ./qt-opensource-linux-x64-5.12.11.run
sudo apt-get install mesa-common-dev 安装 openGL 库
sudo apt-get install libxcb-xinerama0
打开文档 gedit ~/.bashrc
添加 export PATH=/opt/Qt5.12.11/Tools/QtCreator/bin:$PATH
source ~/.bashrc
qtcreator  

//VIRTUALBOX
linux add virtualbox disc command:
sudo apt install build-essential dkms linux-headers-$(uname -r)

//ShareUbuntu
sudo adduser $USER vboxsf

//SQLITE3
sudo apt install sqlite sqlite3
sqlite3 -version
sqlite3 test.db
[EXIT: CTRL+D]
sudo apt-get install sqlitebrowser
