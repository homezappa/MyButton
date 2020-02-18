# MyButton
Arduino library to use buttons

Members:
MyButton();									          // Constructor
void begin(uint8_t);				          // #Pin
void begin(uint8_t,uint8_t);				  // #Pin, INPUT_TYPE 
void begin(uint8_t,uint8_t,uint8_t);	// #Pin, INPUT_TYPE, msec long pushed
bool isPushed();
bool wasPushed();
bool wasLongPushed();
void setPushDelay(uint8_t);
void setLongPushDelay(uint8_t);
void read();							            // You HAVE to call this at the beginning of loop()

Libreria Ardino per l'uso dei pulsanti.
Permette di sapere:
- Se un pulsante è premuto in questo momento (è in stato HIGH)
- Se un pulsante è stato premuto precedentemente (è in stato LOW, ma è passato dallo stato HIGH per almeno 80msec (default, configurabile)
- Se un pulsante è stato premuto A LUNGO precedentemente (è in stato LOW, ma è passato dallo stato HIGH per almeno 2000msec (default, configurabile)

Ho creato questa libreria perchè volevo che un pulsante, se premuto a lungo, eseguisse un menu, se premuto brevemente facesse un'altra cosa, ecc ...
l'esempio accluso è autoesplicativo.
Sono benvenuti suggerimenti
