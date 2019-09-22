#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextStream>
#include <fstream>
#include <iostream>
#include <QFileDialog>
#include <QtGui>
#include <QtCore>

using namespace std;
static int edo;

static int matriz[23][32]={{4,125,500,500,107,108,500,0,0,0,2,1,109,13,10,12,16,17,18,19,21,20,128,129,126,127,123,124,500,111,130,101},
                    {2,100,100,100,100,100,100,100,100,100,2,1,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,3,100,100,100},
                    {2,22,101,101,101,101,101,101,101,101,2,2,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,3,101,101,101},
                    {2,501,501,501,501,501,501,501,501,501,2,2,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501},
                    {4,5,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102},
                    {6,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502},
                    {6,103,7,7,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103},
                    {9,503,503,503,8,8,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503},
                    {9,504,504,504,504,504,504,504,504,504,504,504,504,504,504,504,504,504,504,504,504,504,504,504,504,504,504,504,504,504,504,504},
                    {9,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104},
                    {11,11,11,11,11,11,11,11,11,11,11,11,11,11,505,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11},
                    {506,506,506,506,506,506,506,506,506,506,506,506,506,506,105,506,506,506,506,506,506,506,506,506,506,506,506,506,506,506,506,506},
                    {12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,106,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12},
                    {110,110,110,110,110,110,110,110,110,110,110,110,14,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110},
                    {14,14,14,14,14,14,14,14,14,14,14,14,15,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14},
                    {14,14,14,14,14,14,14,14,14,14,14,14,15,112,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14},
                    {507,507,507,507,507,507,507,507,507,507,507,507,507,507,507,507,507,113,507,507,507,507,507,507,507,507,507,507,507,507,507,507},
                    {508,508,508,508,508,508,508,508,508,508,508,508,508,508,508,508,508,508,114,508,508,508,508,508,508,508,508,508,508,508,508,508},
                    {115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,116,115,115,115,115,115,115,115,115,115,115,115,115},
                    {122,122,122,122,122,122,122,122,122,122,122,122,122,122,122,122,122,122,122,117,122,122,122,122,122,122,122,122,122,122,122,122},
                    {118,118,118,118,118,118,118,118,118,118,118,118,118,118,118,118,118,118,118,119,118,118,118,118,118,118,118,118,118,118,118,118},
                    {120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,121,120,120,120,120,120,120,120,120,120,120,120,120},
                    {509,509,509,509,509,509,509,509,509,509,509,22,509,509,509,509,509,509,509,509,509,509,509,509,509,509,509,509,509,509,509,131}};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Token->setReadOnly(true);
    ui->Error->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int Relaciona(char c){
   int valor;

   if(c>=48 && c<=57){
       return 0;
   }
   if(c>=65 && c<=90){
       return 10;
   }
   if(c>=97 && c<=122){
       return 11;
   }

   switch(c){

   case '.': valor=1;
       break;
   case 'E': valor=2;
       break;
   case 'e': valor=3;
       break;
   case '+': valor=4;
       break;
   case '-': valor=5;
       break;
   case 32:   valor=7;
       break;
   case '\n': valor=8;
               break;
   case '\t': valor=9;
       break;
   case '*': valor=12;
       break;
   case '/': valor=13;
       break;
       case 39: valor=14;
   break;
   case '"': valor=15;
       break;
   case '&': valor=16;
       break;
   case '|': valor=17;
       break;
   case '!': valor=18;
       break;
   case '=': valor=19;
       break;
   case '<':valor=20;
       break;
   case '>': valor=21;
       break;
   case '[': valor=22;
       break;
   case ']': valor=23;
       break;
   case '(': valor=24;
       break;
   case ')': valor=25;
       break;
   case ':': valor=26;
       break;
   case ';': valor=27;
       break;
   case '_': valor=28;
       break;
   case '%': valor=29;
       break;
   case ',': valor=30;
       break;

   default: valor=6;
   }
   return valor;
}
QString Tokens;
QString textoA;
QString texto;
void Token(int e){
    switch(e){
    case 100:
        //cout<<"Palabra reservada"<<endl;
        Tokens+=textoA+" Palabra reservada\n";
        break;
    case 101:
        //cout<<"Identificador"<<endl;
        Tokens+=textoA+" Identificador\n";
        break;
    case 102:
        //cout<<"Entero"<<endl;
        Tokens+=textoA+" Constante Entera\n";
        break;
    case 103:
        //cout<<"Constante decimal"<<endl;
        Tokens+=textoA+" Constante decimal\n";
        break;
    case 104:
        //cout<<"Constante con notación cientifica"<<endl;
        Tokens+=textoA+" Constante con notacion cientifica\n";
        break;
    case 105:
        //cout<<"Constante caracter"<<endl;
        Tokens+=textoA+" Constante caracter\n";
        break;
    case 106:
        //cout<<"Constante String"<<endl;
        Tokens+=textoA+" Constante String\n";
        break;
    case 107:
        //cout<<"Suma"<<endl;
        Tokens+=textoA+" Suma\n";
        break;
    case 108:
        //cout<<"Resta"<<endl;
        Tokens+=textoA+" Resta\n";
        break;
    case 109:
        //cout<<"Multiplicación"<<endl;
        Tokens+=textoA+" Multiplicacion\n";
        break;
    case 110:
        //cout<<"División"<<endl;
        Tokens+=textoA+" Division\n";
        break;
    case 111:
        //cout<<"Modulo"<<endl;
        Tokens+=textoA+" Modulo\n";
        break;
    case 112:
        //cout<<"Comentario"<<endl;
        Tokens+=textoA+" Comentario\n";
        break;
    case 113:
        //cout<<"Operador Y"<<endl;
        Tokens+=textoA+" Operador Y\n";
        break;
    case 114:
        //cout<<"Operador O"<<endl;
        Tokens+=textoA+" Operador O\n";
        break;
    case 115:
        //cout<<"Operador NOT"<<endl;
        Tokens+=textoA+" Operador NOT\n";
        break;
    case 116:
        //cout<<"Operador Diferente"<<endl;
        Tokens+=textoA+" Operador Diferente\n";
        break;
    case 117:
        //cout<<"Igual"<<endl;
        Tokens+=textoA+" Operador Igual\n";
        break;
    case 118:
        //cout<<"Mayor"<<endl;
        Tokens+=textoA+" Operador Mayor\n";
        break;
    case 119:
        //cout<<"Mayor Igual"<<endl;
        Tokens+=textoA+" Operador Mayor igual\n";
        break;
    case 120:
        //cout<<"Menor"<<endl;
        Tokens+=textoA+" Operador Menor\n";
        break;
    case 121:
        //cout<<"Menor Igual"<<endl;
        Tokens+=textoA+" Operador Menor Igual\n";
        break;
    case 122:
        //cout<<"Asignación"<<endl;
        Tokens+=textoA+" Operador de Asignacion\n";
        break;
    case 123:
        //cout<<"Signo dos puntos"<<endl;
        Tokens+=textoA+" Signo dos puntos\n";
        break;
    case 124:
        //cout<<"Signo de cierre"<<endl;
        Tokens+=textoA+" Signo de cierre ;\n";
        break;
    case 125:
        //cout<<"Punto"<<endl;
        Tokens+=textoA+" Punto\n";
        break;
    case 126:
        //cout<<"Parentesis abierto"<<endl;
        Tokens+=textoA+" Parentesis abierto\n";
        break;
    case 127:
        //cout<<"Parentesis cerrado"<<endl;
        Tokens+=textoA+" Paretesis cerrado\n";
        break;
    case 128:
        //cout<<"Corchete abierto"<<endl;
        Tokens+=textoA+" Corchete abierto\n";
        break;
    case 129:
        //cout<<"Corchete cerrado"<<endl;
        Tokens+=textoA+" Corchete cerrado\n";
        break;
    case 130:
        //cout<<"Es una coma"<<endl;
        Tokens+=textoA+" Es una coma\n";
        break;
    case 131:
        //cout<<#Es una libreria"<<endl;
        Tokens+=textoA+" Es una libreria\n";
        break;
    case 132:
        Tokens+=textoA+" Palabra reservada end\n";
        break;
    case 133:
        Tokens+=textoA+" Palabra reservada begin\n";
        break;
    case 134:
        Tokens+=textoA+" Palabra reservada class\n";
        break;
    case 135:
        Tokens+=textoA+" Palabra reservada import\n";
        break;
    case 136:
        Tokens+=textoA+" Palabra reservada def\n";
        break;
    case 137:
        Tokens+=textoA+" Palabra reservada as\n";
        break;
    case 138:
        Tokens+=textoA+" Palabra reservada integer\n";
        break;
    case 139:
        Tokens+=textoA+" Palabra reservada float\n";
        break;
    case 140:
        Tokens+=textoA+" Palabra reservada char\n";
        break;
    case 141:
        Tokens+=textoA+" Palabra reservada string\n";
        break;
    case 142:
        Tokens+=textoA+" Palabra reservada boolean\n";
        break;
    case 143:
        Tokens+=textoA+" Palabra reservada if\n";
        break;
    case 144:
        Tokens+=textoA+" Palabra reservada endif\n";
        break;
    case 145:
        Tokens+=textoA+" Palabra reservada else";
        break;
    case 146:
        Tokens+=textoA+" Palabra reservada endwhile\n";
        break;
    case 147:
        Tokens+=textoA+" Palabra reservada while\n";
        break;
    case 148:
        Tokens+=textoA+" Palabra reservada endfor\n";
        break;
    case 149:
        Tokens+=textoA+" Palabra reservada for\n";
        break;
    case 150:
        Tokens+=textoA+" Palabra reservada enter\n";
        break;
    case 151:
        Tokens+=textoA+" Palabra reservada write\n";
        break;
    case 152:
        Tokens+=textoA+" Palabra reservada read\n";
        break;
    case 153:
        Tokens+=textoA+" Palabra reservada principal\n";
        break;
    case 154:
        Tokens+=textoA+" Palabra reservada elseif\n";
        break;
    case 155:
        Tokens+=textoA+" Palabra reservada do\n";
        break;
    case 156:
        Tokens+=textoA+" Palabra reservada function\n";
        break;
    case 157:
        Tokens+=textoA+" Palabra reservada endfunction\n";
        break;
    case 158:
        Tokens+=textoA+" Palabra reservada null\n";
        break;
    case 159:
        Tokens+=textoA+" Palabra reservada include\n";
        break;
    }

}
QString errores;
void Errores(int e){
    switch(e){
    case 500:
        //cout<<"Error este simbolo no forma parte del lenguaje"<<endl;
        errores+=textoA+" Error este simbolo no forma parte del lenguaje\n";
        break;
    case 501:
        //cout<<"Error no puede declarar un identificador de esa manera"<<endl;
        errores+=textoA+" Error no puede declarar un identificador de esa manera\n";
        break;
    case 502:
        //cout<<"Error no puede escribir una constante usando letras"<<endl;
        errores+=textoA+" Error no puede escribir una constante usando letras\n";
        break;
    case 503:
        //cout<<"Error debe de escribir un numero o un signo positivo o negativo despues de la E o e"<<endl;
        errores+=textoA+" Error debe de escribir un numero o un signo positivo o negativo despues de la E o e\n";
        break;
    case 504:
        //cout<<"Error debe de escribir un numero para completar la expresión"<<endl;
        errores+=textoA+" Error debe de escribir un numero para completar la expresion\n";
        break;
    case 505:
        //cout<<"Error debe de escribir algo entre las '"<<endl;
        errores+=textoA+" Error debe escribir un caracter entre las '\n";
        break;
    case 506:
        //cout<<"Error indefinido"<<endl;
        errores+=textoA+" Error no cerro la '\n";
        break;
    case 507:
        //cout<<"No puede escribir algo entre la expresión"<<endl;
        errores+=textoA+" No puede escribir algo entre la expresion Y\n";
        break;
    case 508:
        //cout<<"No puede escribir algo entre la expresión"<<endl;
        errores+=textoA+" No puede escribir algo entre la expresion O\n";
        break;
    case 509:
        //cout<<"No puedes llamar a una libreria de esa manera
        errores+=textoA+" No puede declara una libreria de esa manera\n";
    case 510:
        errores+=textoA+" 510: Se esperaba la palabra class o import al inicio\n";
        break;
    case 511:
        errores+=textoA+" 511: Se esperaba la palabra class\n";
        break;
    case 512:
        errores+=textoA+" 512: Se esperaba la palabra import o class\n";
        break;
    case 513:
        errores+=textoA+" 513: Se esperaba un identificador, la palabra def o el inicio de un estatuto\n";
        break;
    case 514:
        errores+=textoA+" 514: Se esperaba un identificador\n";
        break;
    case 515:
        errores+=textoA+" 515: Se esperaba la palabra as o ','\n";
        break;
    case 516:
        errores+=textoA+" 516: Se esperaba un tipo de dato\n";
        break;
    case 517:
        errores+=textoA+" 517: Se esperaba un identificador o el  inicio o bien de un estatuto\n";
        break;
    case 518:
        errores+=textoA+" 518: Se esperaba la palabra if\n";
        break;
    case 519:
        errores+=textoA+" 519: Se esperaba la palabra else o endif\n";
        break;
    case 520:
        errores+=textoA+" 520: Se esperaba la palabra while\n";
        break;
    case 521:
        errores+=textoA+" 521: Se esperaba la palabra for\n";
        break;
    case 522:
        errores+=textoA+" 522: La expresión no puede iniciar de esa manera\n";
        break;
    case 523:
        errores+=textoA+" 523: Se esperaba un parentesis cerrado, el operador || o un signo de puntuación\n";
        break;
    case 524:
        errores+=textoA+" 524: La expresión no puede iniciar de esa manera\n";
        break;
    case 525:
        errores+=textoA+" 525: Se esperaba un parentesis cerrado, el operador || o un signo de puntuación\n";
        break;
    case 526:
        errores+=textoA+" 526: La expresión no puede iniciar de esa manera\n";
        break;
    case 527:
        errores+=textoA+" 527: La expresión no puede iniciar de esa manera\n";
        break;
    case 528:
        errores+=textoA+" 528: La expresión no puede iniciar de esa manera\n";
        break;
    case 529:
        errores+=textoA+" 529: Se esperaba un operador relacional o un signo de puntuación\n";
        break;
    case 530:
        errores+=textoA+" 530: La expresión no puede iniciar de esa forma\n";
        break;
    case 531:
        errores+=textoA+" 531: Se esperaba un parentesis cerrado, un operador o un signo de puntuación\n";
        break;
    case 532:
        errores+=textoA+" 532: La expresión no puede iniciar de esa forma\n";
        break;
    case 533:
        errores+=textoA+" 533: Se esperaba un parentesis cerrado, un operador o un signo de puntuación\n";
        break;
    case 534:
        errores+=textoA+" 534: Se esperaba un tipo de constante\n";
        break;
    case 535:
        errores+=textoA+" 535: Se esperaba un operador relacional\n";
        break;
    case 536:
        errores+=textoA+" 536: Se esperaba la palabra enter\n";
        break;
    case 537:
        errores+=textoA+" 537: Se esperaba un identificador\n";
        break;
    case 538:
        errores+=textoA+" 538: Se esperaba la palabra write\n";
        break;
    case 539:
        errores+=textoA+" 539: La expresión no puede iniciar de esa forma\n";
        break;
    case 540:
        errores+=textoA+" 540: Se esperaba un identificador o una coma\n";
        break;
    case 541:
        errores+=textoA+" 541: Se esperaba la palabra read\n";
        break;
    case 542:
        errores+=textoA+" 542: Se esperaba un identificador\n";
        break;
    case 543:
        errores+=textoA+" 543: Se esperaba un identificador o una coma\n";
        break;
    case 544:
        errores+="544: Error entre tipos\n";
        break;
    case 545:
        errores+=textoA+" 545: Variable no declarada\n";
        break;
    default:
        errores+="Revisa tu sintaxis quizas pusiste algo que no debe ir\n";
        break;
    }

}

int evaluaPR(){
    int conta=0;
    std::string cadenaStd = textoA.toStdString();
    for(int i=0;i<textoA.length();i++){
        char car=cadenaStd[i];
        if(car=='\n' || car=='\t' || car==32)
            conta++;
    }
    QString temp=textoA.mid(conta,textoA.length());

    if(textoA=="import" || temp=="import"){
        return 135;
    }
    if(textoA=="class" || temp=="class"){
        return 134;
    }
    if(textoA=="begin" || temp=="begin"){
        return 133;
    }
    if(textoA=="end" || temp=="end"){
        return 132;
    }
    if(textoA=="def" || temp=="def"){
        return 136;
    }
    if(textoA=="as" || temp=="as"){
        return 137;
    }
    if(textoA=="integer" || temp=="integer"){
        return 138;
    }
    if(textoA=="float" || temp=="float"){
        return 139;
    }
    if(textoA=="char" || temp=="char"){
        return 140;
    }
    if(textoA=="string" || temp=="string"){
        return 141;
    }
    if(textoA=="boolean" || temp=="boolean"){
        return 142;
    }
    if(textoA=="if" || temp=="if"){
        return 143;
    }
    if(textoA=="endif" || temp=="endif"){
        return 144;
    }
    if(textoA=="else" || temp=="else"){
        return 145;
    }
    if(textoA=="endwhile" || temp=="endwhile"){
        return 146;
    }
    if(textoA=="while" || temp=="while"){
        return 147;
    }
    if(textoA=="endfor" || temp=="endfor"){
        return 148;
    }
    if(textoA=="for" || temp=="for"){
        return 149;
    }
    if(textoA=="enter" || temp=="enter"){
        return 150;
    }
    if(textoA=="write" || temp=="write"){
        return 151;
    }
    if(textoA=="read" || temp=="read"){
        return 152;
    }
    if(textoA=="principal" || temp=="principal"){
        return 153;
    }
    if(textoA=="elseif" || temp=="elseif"){
        return 154;
    }
    if(textoA=="do" || temp=="do"){
        return 155;
    }
    if(textoA=="function" || temp=="function"){
        return 156;
    }
    if(textoA=="endfunction" || temp=="endfunction"){
        return 157;
    }
    if(textoA=="null" || temp=="null"){
        return 158;
    }
    if(textoA=="include" || temp=="include"){
        return 159;
    }
    return 101;
}

int Analiza(QString cadena){
    std::string cadenaStd = cadena.toStdString();
    edo=0;
    int col;
    char car=cadenaStd[0];

    textoA="";

    int numero=1;
    while(edo<=32){

        col=Relaciona(car);

        edo=matriz[edo][col];

        if(edo==107)
            textoA.append('+');
        if(edo==108)
            textoA.append('-');
        if(edo==109)
            textoA.append('*');
        if(edo==125)
            textoA.append('.');
        if(edo==128)
            textoA.append('[');
        if(edo==129)
            textoA.append(']');
        if(edo==126)
            textoA.append('(');
        if(edo==127)
            textoA.append(')');
        if(edo==124)
            textoA.append(';');
        if(edo==123)
            textoA.append(':');
        if(edo==111)
            textoA.append('%');
        if(edo==130)
            textoA.append(',');

        if(edo<100 || edo>=500){
            textoA.append(car);

        }
        if(edo==103 && (car=='e' || car=='E')){
            if(car=='e')
                textoA.append('e');
            if(car=='E')
                textoA.append('E');
            edo=7;
        }



        if(edo==119 && car=='='){
            textoA.append('=');
            edo=119;
        }

        if(edo==121 && car=='='){
            textoA.append('=');
            edo=121;
        }

        if(edo==116 && car=='='){
            textoA.append('=');
            edo=116;
        }

        if(edo==115 && car=='='){
            textoA.append('=');
            edo=116;
        }

        if(edo==117 && car=='='){
            textoA.append('=');
            edo=117;
        }



        if(edo==112 && car=='/'){
            textoA.append('/');
            edo=112;
        }

        if(edo==10 && car!=39){
            textoA.append(car);
            edo=11;
        }else if(edo==10 && car!=39){
            textoA.append(car);
            edo=105;
        }
        if(edo==105 && car==39){
            textoA.append(car);
            edo=105;
        }
        if(edo==100){
            edo=evaluaPR();
        }

        if(edo==22 && car=='l'){
            edo=22;
        }

        if(edo==22 && car=='y'){
            edo=22;
        }

        if(edo==22 && car=='e'){
            edo=131;
        }

        if(edo==101 && car=='.'){
            textoA.append('.');
            edo=22;
        }

        if(edo==106 && car=='"'){
            textoA.append(car);
            edo=106;
        }

        car=cadenaStd[numero];

        numero++;

    }
    if(textoA=="&&" || textoA.contains("&&")){
        edo=113;
    }else if (textoA.contains("&")) {
        edo=507;
    }
    if(textoA=="||" || textoA.contains("||")){
        edo=114;
    }else if (textoA.contains("|")) {
        edo=508;
    }

    //Elimina lo que hay enfrente de una cadena
    int conta=0;

    for(int i=0;i<textoA.length();i++){
        char car=cadenaStd[i];
        if(car==' ' || car=='\t' || car==32 )
            conta++;
    }
    int longitud=textoA.length();
    texto=texto.remove(0,longitud);
    if(conta!=0){
        textoA.remove(0,conta);
    }

    if(edo>=100 && edo<=199){
        Token(edo);
    }else{
        Errores(edo);
    }

return edo;
}


void MainWindow::on_pushButton_clicked()
{

    Tokens="";
    errores="";
    ui->Token->setPlainText("");
    ui->Error->setPlainText("");
    texto=ui->textoAnalizar->toPlainText();
    while(texto!=""){
    Analiza(texto);

    }
    ui->Token->appendPlainText(Tokens);
    ui->Error->appendPlainText(errores);


}




void MainWindow::on_pushButton_3_clicked()
{

    ui->Token->setPlainText("");
    ui->Error->setPlainText("");
}
