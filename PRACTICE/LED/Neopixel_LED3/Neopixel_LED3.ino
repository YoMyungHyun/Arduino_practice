#include <Adafruit_NeoPixel.h> // 라이브러리 추가

#define PIN 6
#define NUMPIXELS 12 // 12개 픽셀 사용

// 네오픽셀 LED 초기 설정
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void ledOn(byte repeat);  // ledOn, ledOff 함수 선언
void ledOff();

int count = 1; // 변수 초기화

void setup() {
  // put your setup code here, to run once:
  pixels.begin(); // 핀 모드 설정
}

void loop() {
  // put your main code here, to run repeatedly:
  switch(count){ // count 변수가 1~3일 때 네오픽셀 LED의 불이 켜지고 4일 때 불이 꺼짐
    case 1:
    case 2:
    case 3:
    ledOn(count); //count를 매개변수로 해 ledOn() 함수 호출
    delay(2000); //2초간 대기
    count++; //변수 증가
    break;
    case 4: 
    ledOff(); //count 변수가 4일 때 호출
    delay(2000);
    count = 1; // count 변수를 1로 초기화
    break;
  }
}

  void ledOn(byte repeat){ //네오픽셀 LED 소등 기능을 구현한 ledOn() 함수 정의
    for(int q = 0; q < repeat; q++){
      for(int i = 0; i < pixels.numPixels(); i=i+3){ //3 간격으로 반복
      pixels.setPixelColor(i+q, pixels.Color(255,255,255)); //3개 간격으로 픽셀 색깔 설정
    }
  }
  pixels.show(); // 색 출력
  }

  void ledOff(){ //네오픽셀 LED 소등 기능을 구현한 ledOff() 함수 정의
    for(int i = 0; i < pixels.numPixels(); i++){ 
      pixels.setPixelColor(i, pixels.Color(0,0,0)); //전 픽셀 색깔 off
    }
    pixels.show();
  }
