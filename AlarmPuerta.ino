/*MANUEL ALEJANDRO TORRES FONSECA
 *ALARMA PARA PUERTA CON TEMPORIZADOR  
 *FECHA DE CREACION:13 DE MARZO DEL 2018
 *ULTIMA MODIFICACION:13 DE MARZO DEL 2008
 */
#include "LowPower.h"     //es la libreria que se encarga de que el arduino pueda entrar a un modo de ahorro de energia

int zumbador = 13;        //se declara en que pin va ser de la bocina 
int frecuencia =220;      //se declara la cantidad en la cual la bocina va a emitir el pitido 
int puerta=2;             //se declara el pin que va recivir  el estado de la puerta
int ledalarma=3;          //se declara el pin del led que va a indicar cuando la alarma esta activa

void setup(){                   //inicia el metodo setup que se encarga de indicar el estado de cada puerto 
  pinMode(puerta,INPUT);        //se indica que el pin de la puerta va a emitir la señal hacia el arduino para saber si la puerta esta abierta o cerrada        
  pinMode(ledalarma,OUTPUT);    //se indica que el pin del led de la alarma va recibir la señal del arduino
  pinMode(zumbador,OUTPUT);     //se indica que el pin de la bocina va recivir la señal del arduino
  pinMode(6,OUTPUT);            //se indica que se va a usar el pin 6 del arduino para mandar señales
  pinMode(7,OUTPUT);            //se indica que se va a usar el pin 7 del arduino para mandar señales
  pinMode(8,OUTPUT);            //se indica que se va a usar el pin 8 del arduino para mandar señales
  pinMode(9,OUTPUT);            //se indica que se va a usar el pin 9 del arduino para mandar señales
  pinMode(10,OUTPUT);           //se indica que se va a usar el pin 10 del arduino para mandar señales
  pinMode(11,OUTPUT);           //se indica que se va a usar el pin 11 del arduino para mandar señales
  pinMode(12,OUTPUT);           //se indica que se va a usar el pin 12 del arduino para mandar señales
}                               //termino del metodo setup

void display(int a,int b,int c,int d,int e,int f,int g){  //se crea el metodo display que es el que se encarga de ordenar los pines con respecto a sus variables
  digitalWrite(6,a);                                      //se une el pin 6 del arduino con su correspondiente variable 
  digitalWrite(7,b);                                      //se une el pin 7 del arduino con su correspondiente variable
  digitalWrite(8,c);                                      //se une el pin 8 del arduino con su correspondiente variable
  digitalWrite(9,d);                                      //se une el pin 9 del arduino con su correspondiente variable
  digitalWrite(10,e);                                     //se une el pin 10 del arduino con su correspondiente variable
  digitalWrite(11,f);                                     //se une el pin 11 del arduino con su correspondiente variable
  digitalWrite(12,g);                                     //se une el pin 12 del arduino con su correspondiente variable
}                                                         //termino del metodo display

void loop(){                                            //inicio del metodo loop que es el que se encarga de la funcionalida                                             
  LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);       // este es el modo de ahorro de energia en el cual como lo dice su primer parametro dura 8 segundos en esta fase en el cual se apagan los comvertidores de analofico a digital
      if(digitalRead(puerta)==HIGH){                    //este if indica que cuado la pueta este cerrada no va ha hacer nada pero cuando este abierta se va a activar la alarma
         digitalWrite(ledalarma,HIGH);                  //como ya se abrio la puerta entonces se  prende el led de la alarma
         tone(zumbador,frecuencia);                     //se activa el pitido de la alarma con la frecuencia establecida anteriormente
          display(1,0,0,0,1,0,0);                       //se mandan los parametros al metodo display para que nos muestre el numero 5 que es el conteo descendiente de la duracion de la alarma 
          delay(1000);                                  //indica que el numero 5 del display solo va durar 1 segundo 
          display(0,1,0,0,0,1,1);                       //se mandan los parametros al metodo display para que nos muestre el numero 4
          delay(1000);                                  //indica que el numero 4 del display solo va durar 1 segundo
          display(0,0,1,0,1,0,0);                       //se mandan los parametros al metodo display para que nos mustre el numero 3
          delay(1000);                                  //indica que el numero 3 del display solo va durar 1 segundo
          display(0,0,1,0,0,0,1);                       //se mandan los parametros al metodo display para que nos muetre el numero 2
          delay(1000);                                  //indica que el numero 2 del display solo va durar 1 segundo
          display(0,1,1,1,1,1,0);                       //se mandan los parametros al metodo display par que nos muestre el numero 1
          delay(1000);                                  //indica que el numero 1 del display solo va durar 1 segundo
          noTone(zumbador);                             //indica que la bocina y va dejar de emitir el pitido 
      }                                                 //indica el temino del if que se encarga de la alarma 
      digitalWrite(ledalarma,LOW);                      //se apaga el led de la alarma
}                                                       //se termina el metodo loop
