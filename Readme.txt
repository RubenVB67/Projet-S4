PARTIE 1 : script d'install


!/bin/bash
apt-get upgrade ;
apt-get purge -y libreoffice* ;
apt-get install -y cmake libdc1394-22-dev libavcodec-dev ;
apt-get install -y libavdevice-dev libavformat-dev libavresample-dev ;
apt-get install -y libffmpegthumbnailer-dev libavutil-dev ;
apt-get install -y devscripts debhelper cmake libldap2-dev ;
apt-get install -y libgtkmm-3.0-dev libarchive-dev libcurl4-openssl-dev intltool ;
apt-get install -y build-essential cmake pkg-config libjpeg-dev ;
apt-get install -y libtiff5-dev libjasper-dev libavcodec-dev libavformat-dev libswscale-dev ; 
apt-get install -y libv4l-dev libxvidcore-dev libx264-dev libgtk2.0-dev libgtk-3-dev ;
apt-get install -y libatlas-base-dev libblas-dev libeigen2-dev libeigen3-dev liblapack-dev ;
apt-get install -y gfortran python2.7-dev python3-dev python-pip python3-pip python python3 ;
apt-get install -y libgstreamer1.0-dev libgstreamer1.0-0 gstreamer1.0-tools ;
apt-get install -y gstreamer1.0-plugins-base-apps gstreamer1.0-rtsp ;
apt-get install -y libgstreamer1.0-dev libgstreamer-opencv1.0-0 ;
apt-get install -y libgstreamermm-1.0-dev gstreamer1.0-plugins-base-apps ;
apt-get install -y libgstreamermm-1.0-1 ;

//libeigen2-dev, jasper-dev ne marche pas

PARTIE 2 :  étape manuel : 

cd
wget https://github.com/opencv/opencv/archive/4.1.2.zip
unzip 4.1.2.zip
mkdir BUILD
cd BUILD
cmake -D ENABLE_NEON=ON -D ENABLE_NEON=ON ../opencv-4.1.2/

git clone https://gitlab.com/iut-projet/camera.git
sudo make -j4
sudo make install