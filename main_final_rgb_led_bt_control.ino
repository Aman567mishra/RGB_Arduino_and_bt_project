 #include <SoftwareSerial.h>

// Define RGB LED pins
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

// Define Bluetooth module pins
SoftwareSerial bluetooth(2, 3); // RX, TX

int currentMode = 5; // 0: Color Cycle, 1: Smooth Cycle, 2: Rainbow Cycle, 3: Smooth Mode, 4-6: Solid Colors (R, G, B)

void setup() {
  // Initialize RGB LED pins as OUTPUT
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  // Initialize communication with Bluetooth module
  bluetooth.begin(9600);
}

void loop() {
  if (bluetooth.available() > 0) {
    char command = bluetooth.read();

    switch (command) {
      case '1':
        // Color Cycle Mode
        currentMode = 0;
        break;
      case '2':
        // Smooth Cycle Mode
        currentMode = 1;
        break;
        
         case '7':
        // Smooth Cycle Mode 1
        currentMode = 3;
        break;
        
         case '8':
        // Smooth Cycle Mode 2
        currentMode = 4;
        break;
      case '3':
        // Rainbow Cycle Mode
        currentMode = 2;
        break;
        case '9':
        // Rainbow Cycle Mode1
        currentMode = 5;
        break;
      
        case '4':
        // Random Color Mode
        currentMode = 8;
        break;
  
        case '5':
        // Random Color Mode
        currentMode = 9;
        break;
        case '6':
        // Random Color slow Mode
        currentMode = 10;
        break;
        
        case 'a':
        // Solid Red Mode
        currentMode = 50;
        setColor(255, 0, 0);
        break;
      case 'b':
        // Solid Green Mode
        currentMode = 51;
        setColor(0, 255, 0);
        break;
      case 'c':
        // Solid Blue Mode
        currentMode = 52;
        setColor(0, 0, 255);
        break;

        case 'd':
        // Yellow
        currentMode = 53;
        setColor(255, 255, 0);
        break;
      case 'e':
         // Magenta
        currentMode = 54;
        setColor(255, 0, 255);
        break;
      case 'f':
        // Cyan
        currentMode = 55;
        setColor(255, 128, 0);
        break;

         case 'g':
        // Solid Red Mode
        currentMode = 56;
        setColor(1, 254, 255);
        break;
      case 'h':
        // Solid Green Mode
        currentMode = 57;
        setColor(255, 128, 0);
        break;
      case 'i':
        // Solid Blue Mode
        currentMode = 58;
        setColor(255, 255, 0);
        break;

        case 'j':
        // Yellow
        currentMode = 59;
        setColor(255, 255, 0);
        break;
      case 'k':
         // Magenta
        currentMode = 60;
        setColor(255, 0, 255);
        break;
      case 'l':
        // Cyan
        currentMode = 61;
        setColor(255, 128, 0);
        break;


         case 'm':
        // Solid Red Mode
        currentMode = 62;
        setColor(255, 255, 0);
        break;
      case 'n':
        // Solid Green Mode
        currentMode = 63;
        setColor(0, 255, 0);
        break;
      case 'o':
        // Solid Blue Mode
        currentMode = 64;
        setColor(128, 0, 255);
        break;

        case 'p':
        // Yellow
        currentMode = 65;
        setColor(255, 255, 0);
        break;
      case 'q':
         // Magenta
        currentMode = 66;
        setColor(255, 0, 255);
        break;
      case 'r':
        // Cyan
        currentMode = 67;
        setColor(255, 128, 0);
        break;

         case 's':
        // Solid Red Mode
        currentMode = 68;
        setColor(255, 0, 0);
        break;
      case 't':
        // Solid Green Mode
        currentMode = 69;
        setColor(0, 255, 0);
        break;
      case 'u':
        // Solid Blue Mode
        currentMode = 70;
        setColor(0, 0, 255);
        break;

        case 'v':
        // Yellow
        currentMode = 71;
        setColor(255, 255, 0);
        break;
      case 'w':
         // Magenta
        currentMode = 72;
        setColor(255, 0, 255);
        break;
      case 'x':
        // Cyan
        currentMode = 73;
        setColor(255, 128, 0);
        break;
         case 'y':
         // Magenta
        currentMode = 74;
        setColor(255, 0, 255);
        break;
      case 'z':
        // Cyan
        currentMode = 75;
        setColor(255, 128, 0);
        break;
        case 'A':
        // Cyan
        currentMode = 76;
        setColor(255, 128, 0);
        break;
        
        default:
         break;
    }
  }

  // Execute the selected mode
  switch (currentMode) {
    case 0:
      // Color Cycle Mode
      colorCycleMode();
      break;
    case 1:
      // Smooth Cycle Mode
      smoothCycleMode();
      break;
      case 3:
      // Smooth Cycle Mode
      smoothCycleMode1();
      break;
      case 4:
      // Smooth Cycle Mode
      smoothCycleMode2();
      break;
    case 2:
      // Rainbow Cycle Mode
      rainbowCycleMode();
      break;
      
       case 5:
      // Rainbow Cycle Mode
      rainbowCycleMode1();
      break;
    
       case 8:
      // Random Color Mode
      randomColorMode();
      break;
     
       case 9:
      // Random Color Mode
      randomMode();
      break;

      case 10:
      // Random Color Mode
      colorCycleslowMode();
      break;

      case 50:
      // Solid Red Mode
      setColor(255,0 , 0);
      break;
    case 51:
      // Solid Green Mode
      setColor(0, 255, 0);
      break;
    case 52:
      // Solid Blue Mode
      setColor(0, 0, 255);
      break;

       case 53:
     // Yellow
      setColor(0, 55, 255);
      break;
    case 54:
      // Magenta
      setColor(0, 255, 55);
      break;
    case 55:
     // Cyan
      setColor(0, 128, 255);
      break;

      case 56:
      // Solid Red Mode
      setColor(255, 255, 128);
      break;
    case 57:
      // Solid Green Mode
      setColor(128, 255, 255);
      break;
    case 58:
      // Solid Blue Mode
      setColor(128, 128, 255);
      break;

       case 59:
     // Yellow
      setColor(255, 128, 128);
      break;
    case 60:
      // Magenta
      setColor(0, 255, 128);
      break;
    case 61:
     // Cyan
      setColor(128, 0, 255);
      break;
       case 62:
      // Solid Red Mode
      setColor(255, 128, 0);
      break;
    case 63:
      // Solid Green Mode
      setColor(128, 255, 0);
      break;
    case 64:
      // Solid Blue Mode
      setColor(0, 128, 128);
      break;

       case 65:
     // Yellow
      setColor(128, 0, 128);
      break;
    case 66:
      // Magenta
      setColor(128, 128, 0);
      break;
    case 67:
     // Cyan
      setColor(192, 192, 63);
      break;

      case 68:
      // Solid Red Mode
      setColor(128, 128, 128);
      break;
    case 69:
      // Solid Green Mode
      setColor(0, 90, 255);
      break;
    case 70:
      // Solid Blue Mode
      setColor(0, 0, 0);
      break;

       case 71:
     // Yellow
      setColor(0, 156, 184);
      break;
    case 72:
      // Magenta
      setColor(0, 115, 255);
      break;
    case 73:
     // Cyan
      setColor(255, 127, 255);
      break;
        case 74:
      // Magenta
      setColor(37, 90, 223);
      break;
    case 75:
     // Cyan
      setColor(0, 40, 255);
      break;
      case 76:
     // Cyan
      setColor(255, 255, 255);
      break;

      default:
      break;
  }
}

// Function to set RGB color
void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}

// Function for color cycle mode (unchanged)
void colorCycleMode() {
  int r, g, b;

  for (int i = 0; i < 256; i++) {
    r = 255 - i;
    g = i;
    b = 0-1;
    setColor(r, g, b);
    delay(20);
  }

  
  for (int i = 0; i < 256; i++) {
    r = i;
    g = 0-1;
    b = 255 - i;
    setColor(r, g, b);
    delay(20);
  }
  for (int i = 0; i < 256; i++) {
    r = 0-1;
    g = 255 - i;
    b = i;
    setColor(r, g, b);
    delay(20);
  }

}

// Function for smooth cycle mode (unchanged)
void smoothCycleMode() {
  int r, g, b;

  for (int i = 0; i < 256; i++) {
    r = 127 * (1 + sin(0.05 * i));
    g = 127 * (1 + sin(0.05 * i + 2.094));
    b = 127 * (1 + sin(0.05 * i + 4.188));
    setColor(r, g, b);
    delay(40);
  }
}
void smoothCycleMode1() {
  int r, g, b;

  for (int i = 0; i < 256; i++) {
    g = 127 * (1 + sin(0.05 * i));
    r = 127 * (1 + sin(0.05 * i + 2.094));
    b = 127 * (1 + sin(0.05 * i + 4.188));
    setColor(r, g, b);
    delay(40);
  }
}
void smoothCycleMode2() {
  int r, g, b;

  for (int i = 0; i < 256; i++) {
    b = 127 * (1 + sin(0.05 * i));
    g = 127 * (1 + sin(0.05 * i + 2.094));
    r = 127 * (1 + sin(0.05 * i + 4.188));
    setColor(r, g, b);
    delay(40);
  }
}

// Function for rainbow cycle mode (unchanged)
void rainbowCycleMode() {
  int r, g, b;

  for (int i = 0; i < 256; i++) {
    r = 0;
    g = i;
    b = 255 - i;
    setColor(r, g, b);
    delay(10);
  }
  for (int i = 0; i < 256; i++) {
    r = i;
    g = 255 - i;
    b = 0;
    setColor(r, g, b);
    delay(10);
  }
  
  for (int i = 0; i < 256; i++) {
    r = 255 - i;
    g = 0;
    b = i;
    setColor(r, g, b);
    delay(10);
  }

  
}

// Function for rainbow cycle mode (unchanged)
void rainbowCycleMode1() {
  int r, g, b;

  for (int i = 0; i < 256; i++) {
    r = 0;
    g = i;
    b = 255 - i;
    setColor(r, g, b);
    delay(150);
  }
  for (int i = 0; i < 256; i++) {
    r = i;
    g = 255 - i;
    b = 0;
    setColor(r, g, b);
    delay(150);
  }
  
  for (int i = 0; i < 256; i++) {
    r = 255 - i;
    g = 0;
    b = i;
    setColor(r, g, b);
    delay(150);
  }

  
}
// Function for Random Color mode
void randomColorMode() {
  int redValue = random(256);
  int greenValue = random(256);
  int blueValue = random(256);
  setColor(redValue, greenValue, blueValue);
  delay(1000); // Delay between color changes (1 second)
}
// Function for Random Color mode
void randomMode() {
  int redValue = random(256);
  int greenValue = random(256);
  int blueValue = random(256);
  setColor(redValue, greenValue, blueValue);
  delay(200); // Delay between color changes (1 second)
}

// Function for color cycle mode (unchanged)
void colorCycleslowMode() {
  int r, g, b;

 
  for (int i = 0; i < 256; i++) {
    r = i;
    g = 0;
    b = 255 - i;
    setColor(r, g, b);
    delay(150);
  }
  for (int i = 0; i < 256; i++) {
    r = 255 - i;
    g = i;
    b = 0;
    setColor(r, g, b);
    delay(150);
  }
  for (int i = 0; i < 256; i++) {
    r = 0;
    g = 255 - i;
    b = i;
    setColor(r, g, b);
    delay(150);
  }

}
