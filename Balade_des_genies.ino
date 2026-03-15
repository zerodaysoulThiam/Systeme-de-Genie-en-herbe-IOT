#include <MD_Parola.h>
#include <MD_MAX72xx.h>

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define HARDWARE_TYPE MD_MAX72XX :: FC16_HW
#define MAX_DEVICES 4 // 4 blocs
#define CS_PIN 9

// crée une instance de la classe
MD_Parola ledMatrix = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
String text;

void  setup () { 

 Serial.begin(9600);

ledMatrix.begin();     // initialise l'objet   
ledMatrix. setIntensity (0);  // définit la luminosité de l'affichage matriciel LED (de 0 à 15)   
ledMatrix. displayClear ();   // efface l'affichage de la matrice LED   
text.reserve(30); 

}  

void loop() {
if (Serial.available()) {   // s'il y a des données à venir     
 text = Serial.readStringUntil('\n'); // lit la chaîne jusqu'à rencontrer le caractère de nouvelle ligne  

 ledMatrix.displayClear();  // efface l'affichage de la matrice LED
 ledMatrix.displayText(text.c_str(), PA_CENTER, 0, 0, PA_PRINT, PA_NO_EFFECT); 
 //ledMatrix.displayScroll(text.c_str(), PA_CENTER, PA_SCROLL_LEFT, 100);
Serial.print("LED Matrix displayed: ");// rapporte l'action à l'application pour smartphone 
  Serial.println(text);
  }
  if (ledMatrix.displayAnimate()) {
    ledMatrix.displayReset();
  }
}