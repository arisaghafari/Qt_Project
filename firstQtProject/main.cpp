#include <QApplication>
#include <QLabel> //for display label

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QLabel *label = new QLabel("my first QT Project"); //create label and print to it
    label ->setWindowTitle("my first app :)"); //label title
    label ->resize(600, 200);//set a size for label
    label ->show(); //show label
    return app.exec();
}
