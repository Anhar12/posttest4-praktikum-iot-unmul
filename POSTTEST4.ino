#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <DHT.h>

// Wifi network station credentials
#define WIFI_SSID "punya gw"
#define WIFI_PASSWORD "slebew123"

// Telegram BOT Token (Get from Botfather)
#define BOT_TOKEN "6807489929:AAEDtVdpKDAHIt7vegJOFetAGJPpGg8jP0U"

const unsigned long BOT_MTBS = 1000; // mean time between scan messages

X509List cert(TELEGRAM_CERTIFICATE_ROOT);
WiFiClientSecure secured_client;
UniversalTelegramBot bot(BOT_TOKEN, secured_client);
unsigned long bot_lasttime; // last time messages' scan has been done

// Sensor Pins
#define DHTPIN D2
#define LEDANHAR D8
#define LEDSABAN D7
#define LEDRANGGA D6
#define LEDGENERAL D1
#define DHTTYPE DHT11 //Mengatur TYPE DHT (Karena ada 2 jenis [DHT11 & DHT22])

DHT dht(DHTPIN, DHTTYPE);

void handleNewMessages(int numNewMessages) {
  Serial.print("Handle New Messages: ");
  Serial.println(numNewMessages);

  for (int i = 0; i < numNewMessages; i++) {
    String chat_id = bot.messages[i].chat_id;
    String text = bot.messages[i].text;
    String from_name = bot.messages[i].from_name;
    String user_id = bot.messages[i].from_id;
    if (from_name == ""){
      from_name = "Guest";
    }

    float h = dht.readHumidity();
    float t = dht.readTemperature();
    
    if (text == "/LedAnharOn") {
      if (user_id == "1433570446"){
        if (digitalRead(LEDANHAR)){
          bot.sendMessage(chat_id, "Led Anhar is Already ON", "");
        } else {
          digitalWrite(LEDANHAR, HIGH); 
          bot.sendMessage(chat_id, "Led Anhar is ON", "");
        }
      } else {
        bot.sendMessage(chat_id, "Access Denied, You're not Anhar", "");
      }
    }

    if (text == "/LedSabanOn") {
      if (user_id == "5212755706"){
        if (digitalRead(LEDSABAN)){
          bot.sendMessage(chat_id, "Led Saban is Already ON", "");
        } else {
          digitalWrite(LEDSABAN, HIGH); 
          bot.sendMessage(chat_id, "Led Saban is ON", "");
        }
      } else {
        bot.sendMessage(chat_id, "Access Denied, You're not Saban", "");
      }
    }

    if (text == "/LedRanggaOn") {
      if (user_id == "1304550048"){
        if (digitalRead(LEDRANGGA)){
          bot.sendMessage(chat_id, "Led Rangga is Already ON", "");
        } else {
          digitalWrite(LEDRANGGA, HIGH); 
          bot.sendMessage(chat_id, "Led Rangga is ON", "");
        }
      } else {
        bot.sendMessage(chat_id, "Access Denied, You're not Rangga", "");
      }
    }

    if (text == "/LedGeneralOn") {
      if (digitalRead(LEDGENERAL)){
        bot.sendMessage(chat_id, "Led General is Already ON", "");
      } else {
        digitalWrite(LEDGENERAL, HIGH); 
        bot.sendMessage(chat_id, "Led General is ON", "");
      }
    }

    if (text == "/LedAnharOff") {
      if (user_id == "1433570446"){
        if (!digitalRead(LEDANHAR)){
          bot.sendMessage(chat_id, "Led Anhar is Already Off", "");
        } else {
          digitalWrite(LEDANHAR, LOW); 
          bot.sendMessage(chat_id, "Led Anhar is Off", "");
        }
      } else {
        bot.sendMessage(chat_id, "Access Denied, You're not Anhar", "");
      }
    }
    
    if (text == "/LedSabanOff") {
      if (user_id == "5212755706"){
        if (!digitalRead(LEDSABAN)){
          bot.sendMessage(chat_id, "Led Saban is Already Off", "");
        } else {
          digitalWrite(LEDSABAN, LOW); 
          bot.sendMessage(chat_id, "Led Saban is Off", "");
        }
      } else {
        bot.sendMessage(chat_id, "Access Denied, You're not Saban", "");
      }
    }
    
    if (text == "/LedRanggaOff") {
      if (user_id == "1304550048"){
        if (!digitalRead(LEDRANGGA)){
          bot.sendMessage(chat_id, "Led Rangga is Already Off", "");
        } else {
          digitalWrite(LEDRANGGA, LOW); 
          bot.sendMessage(chat_id, "Led Rangga is Off", "");
        }
      } else {
        bot.sendMessage(chat_id, "Access Denied, You're not Rangga", "");
      }
    }

    if (text == "/LedGeneralOff") {
      if (digitalRead(LEDGENERAL)){
        digitalWrite(LEDGENERAL, LOW); 
        bot.sendMessage(chat_id, "Led General is OFF", "");
      } else {
        bot.sendMessage(chat_id, "Led General is Already OFF", "");
      }
    }

    if (text == "/InfoLED") {
      String message = "LED General Status\t: ";
      if(digitalRead(LEDGENERAL)) {
        message += "ON";
      } else {
        message += "OFF";
      }
      
      message += "\nLed Anhar Status\t: ";
      if(digitalRead(LEDANHAR)) {
        message += "ON";
      } else {
        message += "OFF";
      }

      message += "\nLed Saban Status\t: ";
      if(digitalRead(LEDSABAN)) {
        message += "ON";
      } else {
        message += "OFF";
      }

      message += "\nLed Rangga Status\t: ";
      if(digitalRead(LEDRANGGA)) {
        message += "ON";
      } else {
        message += "OFF";
      }
      
      bot.sendMessage(chat_id, message, "");
    }
    
    if (text == "/InfoDHT") {
      String message = "";
      message += "Suhu\t: "+ String(t) + "°C\n";
      message += "Kelembapan\t: "+ String(h) + " %";
      bot.sendMessage(chat_id, message, "");
    }

    if (text == "/start") {
      digitalWrite(LEDGENERAL, LOW);
      digitalWrite(LEDANHAR, LOW);
      digitalWrite(LEDRANGGA, LOW);
      digitalWrite(LEDSABAN, LOW);
      String welcome = "Welcome to IoT Telegram Bot, " + from_name + ".\n";
      welcome += "List of Commands:\n\n";
      welcome += "/LedGeneralOn : to switch the Led General ON\n";
      welcome += "/LedAnharOn : to switch the Led Anhar ON\n";
      welcome += "/LedSabanOn : to switch the Led Saban ON\n";
      welcome += "/LedRanggaOn : to switch the Led Rangga ON\n";
      welcome += "/LedGeneralOff : to switch the Led General OFF\n";
      welcome += "/LedAnharOff : to switch the Led Anhar OFF\n";
      welcome += "/LedSabanOff : to switch the Led Saban OFF\n";
      welcome += "/LedRanggaOff : to switch the Led Rangga OFF\n";
      welcome += "/InfoLED : Returns current status of LED\n";
      welcome += "/InfoDHT : Returns temperature and humidity status of DHT11\n";
      bot.sendMessage(chat_id, welcome, "Markdown");
    }
  }
}


void setup()
{
  Serial.begin(115200);
  Serial.println();

  // Sensor Pin Mode
  pinMode(LEDANHAR, OUTPUT);
  pinMode(LEDRANGGA, OUTPUT);
  pinMode(LEDSABAN, OUTPUT);
  pinMode(LEDGENERAL, OUTPUT);
  dht.begin();

  // attempt to connect to Wifi network:
  configTime(0, 0, "pool.ntp.org");      // get UTC time via NTP
  secured_client.setTrustAnchors(&cert); // Add root certificate for api.telegram.org
  Serial.print("Connecting to Wifi SSID ");
  Serial.print(WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.print("\nWiFi connected. IP address: ");
  Serial.println(WiFi.localIP());

  // Check NTP/Time, usually it is instantaneous and you can delete the code below.
  Serial.print("Retrieving time: ");
  time_t now = time(nullptr);
  while (now < 24 * 3600)
  {
    Serial.print(".");
    delay(100);
    now = time(nullptr);
  }
  Serial.println(now);
}

void loop() {
  if (millis() - bot_lasttime > BOT_MTBS) {
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    
    while (numNewMessages) {
      Serial.println("Got response");
      handleNewMessages(numNewMessages);
      numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }

    bot_lasttime = millis();
  }
}