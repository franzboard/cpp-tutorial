# How to compile / run this example on Raspbian stretch

## Install qt:
```
sudo apt update && sudo apt install qt5-default -y
```

## Prepare environment and compile
In directory qt-01 execute:
```
qmake -project "QT += widgets"
qmake
make
```

## Run the program
```
./qt-01
```


