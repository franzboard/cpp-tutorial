#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
int main(int argc, char *argv[ ]){
   QApplication app(argc, argv);
   QLabel label("Hi BULME-Raspi!");
   label.resize(200, 40);
   label.show();
   return app.exec();
}

