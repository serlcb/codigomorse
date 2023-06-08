// LED conectado ao pino 10 
int ledPin = 10;
// Buzzer conectado ao pino 11
int buzzerPin=11;
// executa uma vez, quando o sketch inicia
int unidade=100;
// executa uma vez, quando o sketch inicia
String entrada="";
String ultimaentrada="";


void setup() {
  // define o pino como saída
  pinMode(ledPin, OUTPUT); 
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void ponto(int conta) {

  for (int i=0; i<conta; i++) {
    digitalWrite(ledPin, HIGH); // acende o LED
    tone(buzzerPin, 2200, unidade); // Faz o buzzer tocar um sinal de 2200hz por unidade ms
    delay(unidade); // espera unidade ms por causa do LED, a função tone retorna antes de completar o delay dela
    digitalWrite(ledPin, LOW); // apaga o LED 
    delay(unidade);// espera unidade ms
  }
}

void traco(int conta) {

  for (int i=0; i<conta; i++) {
    digitalWrite(ledPin, HIGH); // acende o LED
    tone(buzzerPin, 2200, 3*unidade); // Faz o buzzer tocar um sinal de 2200hz por 3*unidade ms
    delay(3*unidade); // espera 3*unidade ms por causa do LED, a função tone retorna antes de completar o delay dela
    digitalWrite(ledPin, LOW); // apaga o LED 
    delay(unidade);// espera unidade ms
  }
}

void sinaliza(char caracter) {

  switch(caracter) {
    case 'A':
      ponto(1);
      traco(1);
      delay(3*unidade);
      break;
    case 'B':
      traco(1);
      ponto(3);
      delay(3*unidade);
      break;
    case 'C':
      traco(1);
      ponto(1);
      traco(1);
      ponto(1);
      delay(3*unidade);
      break;
    case 'D':
      traco(1);
      ponto(2);
      delay(3*unidade);
      break;
    case 'E':
      ponto(1);
      delay(3*unidade);
      break;
    case 'F':
      ponto(2);
      traco(1);
      ponto(1);
      delay(3*unidade);
      break;
    case 'G':
      traco(2);
      ponto(1);
      delay(3*unidade);
      break;
    case 'H':
      ponto(4);
      delay(3*unidade);
      break;
    case 'I':
      ponto(2);
      delay(3*unidade);
      break;
    case 'J':
      ponto(1);
      traco(3);
      delay(3*unidade);
      break;
    case 'K':
      traco(1);
      ponto(1);
      traco(1);
      delay(3*unidade);
      break;
    case 'L':
      ponto(1);
      traco(1);
      ponto(2);
      delay(3*unidade);
      break;
    case 'M':
      traco(2);
      delay(3*unidade);
      break;
    case 'N':
      traco(1);
      ponto(1);
      delay(3*unidade);
      break;
    case 'O':
      traco(3);
      delay(3*unidade);
      break;
    case 'P':
      ponto(1);
      traco(2);
      ponto(1);
      delay(3*unidade);
      break;
    case 'Q':
      traco(2);
      ponto(1);
      traco(1);
      delay(3*unidade);
      break;
    case 'R':
      ponto(1);
      traco(1);
      ponto(1);
      delay(3*unidade);
      break;
    case 'S':
      ponto(3);
      delay(3*unidade);
      break;
    case 'T':
      traco(1);
      delay(3*unidade);
      break;
    case 'U':
      ponto(2);
      traco(1);
      delay(3*unidade);
      break;
    case 'V':
      ponto(3);
      traco(1);
      delay(3*unidade);
      break;
    case 'W':
      ponto(1);
      traco(2);
      delay(3*unidade);
      break;
    case 'X':
      traco(1);
      ponto(2);
      traco(1);
      delay(3*unidade);
      break;
    case 'Y':
      traco(1);
      ponto(1);
      traco(2);
      delay(3*unidade);
      break;
    case 'Z':
      traco(2);
      ponto(2);
      delay(3*unidade);
      break;
    case '1':
      ponto(1);
      traco(4);
      delay(3*unidade);
      break;
    case '2':
      ponto(2);
      traco(3);
      delay(3*unidade);
      break;
    case '3':
      ponto(3);
      traco(2);
      delay(3*unidade);
      break;
    case '4':
      ponto(4);
      traco(1);
      delay(3*unidade);
      break;
    case '5':
      ponto(5);
      delay(3*unidade);
      break;
    case '6':
      traco(1);
      ponto(4);
      delay(3*unidade);
      break;
    case '7':
      traco(2);
      ponto(3);
      delay(3*unidade);
      break;
    case '8':
      traco(3);
      ponto(2);
      delay(3*unidade);
      break;
    case '9':
      traco(4);
      ponto(1);
      delay(3*unidade);
      break;
    case '0':
      traco(5);
      delay(3*unidade);
      break;
    case '.':
      ponto(1);
      traco(1);
      ponto(1);
      traco(1);
      ponto(1);
      traco(1);
      delay(3*unidade);
      break;
    case ',':
      traco(2);
      ponto(2);
      traco(2);
      delay(3*unidade);
      break;
    case '?':
      ponto(2);
      traco(2);
      ponto(2);      
      delay(3*unidade);
      break;
  }
}

// executa repetidas vezes 
void loop() {
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  entrada=Serial.readStringUntil('\n');
  if (entrada.length()==0) {
    entrada=ultimaentrada;
  } else {
    ultimaentrada=entrada;
  }
  Serial.println(entrada);
  for (int i=0; i < entrada.length();i++) {
    if ((entrada.charAt(i) != ' ') && (entrada.charAt(i) != '\n')) {
      sinaliza(entrada.charAt(i));
    } else if (entrada.charAt(i) == ' ') {
      delay(7*unidade);
    }
  }
  delay(10*unidade);
}