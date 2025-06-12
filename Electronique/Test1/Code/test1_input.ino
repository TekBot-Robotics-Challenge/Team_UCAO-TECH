// Test 1 - GY-521 (MPU6050) avec LCD et Arduino UNO

#include <Wire.h>                    // Bibliothèque I2C
#include <Adafruit_MPU6050.h>       // Contrôle du capteur MPU6050
#include <Adafruit_Sensor.h>        // Structures capteur génériques
#include <LiquidCrystal_I2C.h>      // Contrôle de l'écran LCD I2C

// Déclaration des objets

Adafruit_MPU6050 mpu;
LiquidCrystal_I2C lcd(0x27, 16, 2); // Adresse I2C

// Variables capteur

float ax, ay, az;                  // Accélérations lues à chaque boucle
float ax_offset = 0, ay_offset = 0, az_offset = 0;  // Offsets pour la calibration

void setup() {
  // Initialisation communication série et I2C
  Serial.begin(115200);
  Wire.begin();
  // Initialisation du capteur MPU6050
  if (!mpu.begin()) {
    Serial.println("Erreur : capteur MPU6050 non détecté !");
    while (1); // Stop si capteur absent
  }
  // Initialisation de l'écran LCD
 
  lcd.init();           // Démarrage
  lcd.backlight();      // Active le rétroéclairage
  lcd.setCursor(0, 0);
  lcd.print("Calibration..."); 
  delay(2000);          // Pause pour stabilité avant la lecture

  // Phase de calibration (offset initial)

  float temp_x = 0, temp_y = 0, temp_z = 0;
  sensors_event_t a, g, temp;

  for (int i = 0; i < 50; i++) {   // Moyenne sur 50 mesures
    mpu.getEvent(&a, &g, &temp);
    temp_x += a.acceleration.x;
    temp_y += a.acceleration.y;
    temp_z += a.acceleration.z;
    delay(10);
  }

  ax_offset = temp_x / 50;   // Offsets enregistrés comme référence initiale
  ay_offset = temp_y / 50;
  az_offset = temp_z / 50;

  // Message "Prêt !"
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Pret !");
  delay(1000);
}

void loop() {
  // Lecture des données

  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  // Compensation des offsets (accélération relative)
  ax = a.acceleration.x - ax_offset;
  ay = a.acceleration.y - ay_offset;
  az = a.acceleration.z - az_offset;

  // Détection de direction dominante
 
  String direction = "IMMOBILE";
  float seuil = 1.5; // m/s² – seuil minimum pour ignorer micro-mouvements

  if (abs(ax) > abs(ay) && abs(ax) > abs(az) && abs(ax) > seuil) {
    direction = (ax > 0) ? "DROITE" : "GAUCHE";
  }
  else if (abs(ay) > abs(ax) && abs(ay) > abs(az) && abs(ay) > seuil) {
    direction = (ay > 0) ? "AVANT" : "ARRIERE";
  }
  else if (abs(az) > abs(ax) && abs(az) > abs(ay) && abs(az) > seuil) {
    direction = (az > 0) ? "HAUT" : "BAS";
  }

  // Calcul de l'accélération dominante

  float acc_value = max(max(abs(ax), abs(ay)), abs(az));

  // Affichage LCD
 
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Dir: " + direction);
  lcd.setCursor(0, 1);
  lcd.print("Acc: ");
  lcd.print(acc_value, 2);
  lcd.print(" m/s2");

  // Sortie série (debug/calibration avancée)

  Serial.print("ax: "); Serial.print(ax, 2);
  Serial.print(" | ay: "); Serial.print(ay, 2);
  Serial.print(" | az: "); Serial.print(az, 2);
  Serial.print(" | Dir: "); Serial.println(direction);

  delay(300); // Anti-clignotement / filtrage
}
