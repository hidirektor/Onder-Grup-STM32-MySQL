/* USER CODE BEGIN Header */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <i2c-lcd.h>

#define wifi_ssid "Zyxel_DC93"
#define wifi_password "VPDD53RXCK"


void menu(void);
void bekle(void);
void i2cTest(void);
void dataTask(void *pvParameters);
void programTask(void *pvParameters);
void Send_GET_Request(char* server, char* api, uint8_t led);
void WiFi_Init(void);
void WiFi_Connect(void);

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
char* ssid = "ONDERLIFT_PERSONEL";
char* password = "OnderGrup";

char* server1 = "yst.com.tr";
char* server2 = "yst.com.tr";
char* api1 = "/api/api.php";
char* api2 = "/api/api2.php";
uint8_t eepromData[63];
uint8_t kaydedilenDeger=0;
char snum[5];
unsigned long millis=0;
unsigned long timer=0;
unsigned long timer1=0;
unsigned long timer2=0;
unsigned long timer3=0;
unsigned long makinecalistmr1=0;
uint8_t calismaSayisi=0;
uint8_t calismaSayisi1=0;
uint8_t calismaSayisi10=0;
uint8_t calismaSayisi100=2;
uint8_t calismaSayisi1000=1;
uint8_t calismaSayisi10000=0;
uint8_t menuSayac=0;
uint8_t durakSayisi=0;
uint8_t calismaSekli=0;
uint8_t acilStop1=0;
uint8_t emniyetCercevesi=0;
uint8_t yavaslamaLimit=0;
uint8_t altLimit=0;
uint8_t basincSalteri=0;
uint8_t kapiSivici=0;
uint8_t kapi1Tip=0;
uint8_t kapi2Tip=0;
uint8_t kapitablaTip=0;
uint8_t yukariYavasLimit=0;
uint8_t devirmeYuruyusSecim=0;
uint8_t devirmeYukariIleriLimit=0;
uint8_t devirmeAsagiGeriLimit=0;
uint8_t devirmeSilindirTipi=0;
uint8_t platformSilindirTipi=0;
uint8_t yukariValfTmr=0;
uint8_t asagiValfTmr=0;
uint8_t devirmeYukariIleriTmr=0;
uint8_t devirmeAsagiGeriTmr=0;
uint8_t makineCalismaTmr=0;
uint8_t kapi1AcSure=0;
uint8_t kapi2AcSure=0;
uint8_t kapiTablaAcSure=0;
uint8_t buzzer=0;
bool hafizaYaz=0;
bool hafizaOku=0;
bool ilkOkuma=0;
uint8_t menuGiris=0;
uint8_t butonKontrol=0;
uint8_t butonKontrol2=0;
bool mesajYazildi=0;
bool yukarimotorcalisiyor=0;
bool devmotoryukaricalisiyor=0;
bool devmotorasagicalisiyor=0;
uint8_t asagivalfcalisiyor=0;
bool basgondercalisyukari=0;
bool basgondercalisasagi=0;
bool demoCalismaSayisiYar=0;
uint8_t stopVar=0;
uint8_t kapiSivicVar=0;
uint8_t motorcalisiyor=0;
uint8_t hataVar=0;
uint8_t makineCalisiyor=0;
uint8_t cerceveVar=0;
uint8_t asagiStartKontrol=0;
uint8_t demoMode=0;
uint8_t demoYukariCalis=0;
uint8_t demoAsagiCalis=0;
uint8_t demoDevYukari=0;
uint8_t demoDevAsagi=0;
uint8_t demoMotorCalis=0;


/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
CAN_HandleTypeDef hcan;

I2C_HandleTypeDef hi2c1;

TIM_HandleTypeDef htim1;

UART_HandleTypeDef huart1;

osThreadId defaultTaskHandle;
/* USER CODE BEGIN PV */
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_CAN_Init(void);
static void MX_I2C1_Init(void);
static void MX_TIM1_Init(void);
static void MX_USART1_UART_Init(void);
void StartDefaultTask(void const * argument);

/* USER CODE BEGIN PFP */
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

void bekle(void)
{
	timer1=millis;
    while((HAL_GPIO_ReadPin(ileributonIn_GPIO_Port,ileributonIn_Pin)==1)&&(millis-timer1<1)){ /* Butona basili olduğu surece bekle */
    	butonKontrol=1;
   }
    while((HAL_GPIO_ReadPin(geributonIn_GPIO_Port,geributonIn_Pin)==1)&&(millis-timer1<1)){ /* Butona basili olduğu surece bekle */
    	butonKontrol=1;
   }
    while((HAL_GPIO_ReadPin(yukaributonIn_GPIO_Port,yukaributonIn_Pin)==1)&&(millis-timer1<1)){ /* Butona basili olduğu surece bekle */
    	butonKontrol=1;
   }
    while((HAL_GPIO_ReadPin(asagibutonIn_GPIO_Port,asagibutonIn_Pin)==1)&&(millis-timer1<1)){ /* Butona basili olduğu surece bekle */
    	butonKontrol=1;
   }
    while((HAL_GPIO_ReadPin(enterbutonIn_GPIO_Port,enterbutonIn_Pin)==1)&&(millis-timer1<1)){ /* Butona basili olduğu surece bekle */
    	butonKontrol=1;
   }
    while((HAL_GPIO_ReadPin(kapiacIn_GPIO_Port,kapiacIn_Pin)==1)&&(millis-timer1<1)){
    	butonKontrol=1;
    }
    while((HAL_GPIO_ReadPin(ustkapiacIn_GPIO_Port,ustkapiacIn_Pin)==1)&&(millis-timer1<1)){
    	butonKontrol=1;
    }
    while((HAL_GPIO_ReadPin(tablakapiacIn_GPIO_Port,tablakapiacIn_Pin)==1)&&(millis-timer1<1)){
    	butonKontrol=1;
    }
}

void menu(void)     //--------------------------------------------------------menuye girdik
{
	if ((HAL_GPIO_ReadPin(ileributonIn_GPIO_Port,ileributonIn_Pin)==1)&&(butonKontrol==0)){
		menuSayac=menuSayac+1;
		if (menuSayac==28){    //MENÜ BÜYÜDÜKÇE DE�?İ�?TİR
			menuSayac=1;
		}


		if((menuSayac==16)&&(devirmeYuruyusSecim==0)){
			menuSayac=19;
		}

		if((menuSayac==8)&&(kapiSivici==0)){
			menuSayac=14;
		}
		if ((menuSayac==12)&&(kapiSivici==1)){			// kapi kat sivici aktif ise tabla kapı hariç ayarlar gösterilir.
			menuSayac=14;
		}
		if((menuSayac==8)&&(kapiSivici==2)){			// tabla aktif ise kat harici kapılar gösterilir.
			menuSayac=12;
		}

		if((menuSayac==9)&&(kapi1Tip==1)){
			menuSayac=10;
		}

		if((menuSayac==11)&&(kapi2Tip==1)&&(kapiSivici==1)){
			menuSayac=14;
		}
		if((menuSayac==11)&&(kapi2Tip==1)&&(kapiSivici==3)){
			menuSayac=12;
		}

		if((menuSayac==13)&&(kapitablaTip==1)){
			menuSayac=14;
		}

		if((menuSayac==22)&&(devirmeYuruyusSecim==0)){
			menuSayac=24;
		}

		bekle();
	}


	if ((HAL_GPIO_ReadPin(geributonIn_GPIO_Port,geributonIn_Pin)==1)&&(butonKontrol==0)){
		if (menuSayac<=1){
			menuSayac=28;     //MENÜ BÜYÜDÜKÇE DE�?İ�?TİR
		}

		menuSayac=menuSayac-1;
		if((menuSayac==18)&&(devirmeYuruyusSecim==0)){
			menuSayac=15;
		}

		if((menuSayac==13)&&(kapiSivici==0)){
			menuSayac=7;
		}

		if((menuSayac==13)&&(kapiSivici==1)){
			menuSayac=11;
		}

		if((menuSayac==11)&&(kapiSivici==2)){
			menuSayac=7;
		}

		if((menuSayac==9)&&(kapi1Tip==1)){
			menuSayac=8;
		}

		if((menuSayac==11)&&(kapi2Tip==1)){
			menuSayac=10;
		}

		if((menuSayac==13)&&(kapitablaTip==1)){
			menuSayac=12;
		}

		if((menuSayac==23)&&(devirmeYuruyusSecim==0)){
			menuSayac=21;
		}

		bekle();
}

	if (menuSayac==0){
		lcd_print(1,1,"MENUYE  GiRDiNiZ");
		lcd_print(2,1,"    AYARLAR     ");
		}

	if (menuSayac==1){
		lcd_print(1,1,"ACIL STOP SAYISI");
        if(acilStop1==0){
			lcd_print(2,1,"Pasif          ");
		}

		if(acilStop1==1){
			lcd_print(2,1,"1              ");
		}

		if(acilStop1==2){
			lcd_print(2,1,"2              ");
		}

		if(acilStop1==3){
			lcd_print(2,1,"3              ");
		}

	    itoa(acilStop1, snum, 10);
	    lcd_print(2,16,snum);

	    if ((HAL_GPIO_ReadPin(yukaributonIn_GPIO_Port,yukaributonIn_Pin)==1)&&(butonKontrol==0)){
	    	acilStop1=acilStop1+1;
	    	if (acilStop1>3){
	    		acilStop1=0;
	    	}
	    	bekle();
	    }

	    if ((HAL_GPIO_ReadPin(asagibutonIn_GPIO_Port,asagibutonIn_Pin)==1)&&(butonKontrol==0)){
	    	acilStop1=acilStop1-1;
	    	if(acilStop1>4){
	    		acilStop1=3;
	    	}
	    	bekle();
	    }

	    if ((HAL_GPIO_ReadPin(enterbutonIn_GPIO_Port,enterbutonIn_Pin)==1)&&(butonKontrol==0)){
	    	eepromData[0]=acilStop1;
	    	hafizaYaz=1;
	    }
	}

	if (menuSayac==2){
		lcd_print(1,1,"CALISMA SEKLi   ");
		if(calismaSekli==0){
			lcd_print(2,1,"Bastikca cal.  ");
		}

		if(calismaSekli==1){
			lcd_print(2,1,"Bas gonder     ");
		}

		itoa(calismaSekli, snum, 10);
		lcd_print(2,16,snum);

		if ((HAL_GPIO_ReadPin(yukaributonIn_GPIO_Port,yukaributonIn_Pin)==1)&&(butonKontrol==0)&&(devirmeYuruyusSecim==0)){
			calismaSekli=calismaSekli+1;
			if(calismaSekli>1){
				calismaSekli=0;
			}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(asagibutonIn_GPIO_Port,asagibutonIn_Pin)==1)&&(butonKontrol==0)&&(devirmeYuruyusSecim==0)){
			calismaSekli=calismaSekli-1;
	    	if(calismaSekli>0){
	    		calismaSekli=1;
	    	}
			bekle();
		}

		if ((HAL_GPIO_ReadPin(enterbutonIn_GPIO_Port,enterbutonIn_Pin)==1)&&(butonKontrol==0)){
			eepromData[1]=calismaSekli;
			hafizaYaz=1;
		}
	}

	if (menuSayac==3){
			lcd_print(1,1,"EMNIYET CER.   ");
			if(emniyetCercevesi==0){
				lcd_print(2,1,"Pasif          ");
			}

			if(emniyetCercevesi==1){
				lcd_print(2,1,"OND Safety     ");
			}

			itoa(emniyetCercevesi, snum, 10);
			lcd_print(2,16,snum);

			if ((HAL_GPIO_ReadPin(yukaributonIn_GPIO_Port,yukaributonIn_Pin)==1)&&(butonKontrol==0)){
				emniyetCercevesi=emniyetCercevesi+1;
				if(emniyetCercevesi>1){
					emniyetCercevesi=0;
				}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(asagibutonIn_GPIO_Port,asagibutonIn_Pin)==1)&&(butonKontrol==0)){
				emniyetCercevesi=emniyetCercevesi-1;
		    	if(emniyetCercevesi>0){
		    		emniyetCercevesi=1;
		    	}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(enterbutonIn_GPIO_Port,enterbutonIn_Pin)==1)&&(butonKontrol==0)){
				eepromData[2]=emniyetCercevesi;
				hafizaYaz=1;
			}
		}

	if (menuSayac==4){
			lcd_print(1,1,"YAVASLAMA LIMIT ");
			if(yavaslamaLimit==0){
				lcd_print(2,1,"Pasif          ");
			}

			if(yavaslamaLimit==1){
				lcd_print(2,1,"Aktif          ");
			}

			itoa(yavaslamaLimit, snum, 10);
			lcd_print(2,16,snum);

			if ((HAL_GPIO_ReadPin(yukaributonIn_GPIO_Port,yukaributonIn_Pin)==1)&&(butonKontrol==0)){
				yavaslamaLimit=yavaslamaLimit+1;
				if(yavaslamaLimit>1){
					yavaslamaLimit=0;
				}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(asagibutonIn_GPIO_Port,asagibutonIn_Pin)==1)&&(butonKontrol==0)){
				yavaslamaLimit=yavaslamaLimit-1;
		    	if(yavaslamaLimit>0){
		    		yavaslamaLimit=1;
		    	}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(enterbutonIn_GPIO_Port,enterbutonIn_Pin)==1)&&(butonKontrol==0)){
				eepromData[4]=yavaslamaLimit;
				hafizaYaz=1;
			}
		}

	if (menuSayac==5){
			lcd_print(1,1,"ALT LIMIT       ");
			if(altLimit==0){
				lcd_print(2,1,"Pasif          ");
			}

			if(altLimit==1){
				lcd_print(2,1,"Aktif          ");
			}

			itoa(altLimit, snum, 10);
			lcd_print(2,16,snum);

			if ((HAL_GPIO_ReadPin(yukaributonIn_GPIO_Port,yukaributonIn_Pin)==1)&&(butonKontrol==0)){
				altLimit=altLimit+1;
				if(altLimit>1){
					altLimit=0;
				}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(asagibutonIn_GPIO_Port,asagibutonIn_Pin)==1)&&(butonKontrol==0)){
				altLimit=altLimit-1;
		    	if(altLimit>0){
		    		altLimit=1;
		    	}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(enterbutonIn_GPIO_Port,enterbutonIn_Pin)==1)&&(butonKontrol==0)){
				eepromData[5]=altLimit;
				hafizaYaz=1;
			}
		}

	if (menuSayac==6){
			lcd_print(1,1,"BASINC SALTERI ");
			if(basincSalteri==0){
				lcd_print(2,1,"Pasif          ");
			}

			if(basincSalteri==1){
				lcd_print(2,1,"Aktif          ");
			}

			itoa(basincSalteri, snum, 10);
			lcd_print(2,16,snum);

			if ((HAL_GPIO_ReadPin(yukaributonIn_GPIO_Port,yukaributonIn_Pin)==1)&&(butonKontrol==0)){
				basincSalteri=basincSalteri+1;
				if(basincSalteri>1){
					basincSalteri=0;
				}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(asagibutonIn_GPIO_Port,asagibutonIn_Pin)==1)&&(butonKontrol==0)){
				basincSalteri=basincSalteri-1;
		    	if(basincSalteri>0){
		    		basincSalteri=1;
		    	}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(enterbutonIn_GPIO_Port,enterbutonIn_Pin)==1)&&(butonKontrol==0)){
				eepromData[6]=basincSalteri;
				hafizaYaz=1;
			}
		}

	if (menuSayac==7){
			lcd_print(1,1,"  KAPI SIVICI   ");
			if(kapiSivici==0){
				lcd_print(2,1,"Pasif          ");
			}

			if(kapiSivici==1){
				lcd_print(2,1,"KAT KAPISI AKTIF");
			}

			if(kapiSivici==2){
				lcd_print(2,1,"TABLA KAPI AKTIF");

			}
			if(kapiSivici==3){
				lcd_print(2,1,"KAT + TABL AKTIF");
			}

			itoa(kapiSivici, snum, 10);
			lcd_print(2,16,snum);

			if ((HAL_GPIO_ReadPin(yukaributonIn_GPIO_Port,yukaributonIn_Pin)==1)&&(butonKontrol==0)){
				kapiSivici=kapiSivici+1;
				if(kapiSivici>3){
					kapiSivici=0;
				}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(asagibutonIn_GPIO_Port,asagibutonIn_Pin)==1)&&(butonKontrol==0)){
				kapiSivici=kapiSivici-1;
		    	if(kapiSivici>4){
		    		kapiSivici=3;
		    	}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(enterbutonIn_GPIO_Port,enterbutonIn_Pin)==1)&&(butonKontrol==0)){
				eepromData[7]=kapiSivici;
				hafizaYaz=1;
			}
		}



	if (menuSayac==8){
			lcd_print(1,1,"1.KAT KAPI TiPi ");
			if(kapi1Tip==0){
				lcd_print(2,1,"Prudhome       ");
			}

			if(kapi1Tip==1){
				lcd_print(2,1,"Buton kontrollu");
			}

			itoa(kapi1Tip, snum, 10);
			lcd_print(2,16,snum);

			if ((HAL_GPIO_ReadPin(yukaributonIn_GPIO_Port,yukaributonIn_Pin)==1)&&(butonKontrol==0)){
				kapi1Tip=kapi1Tip+1;
				if(kapi1Tip>1){
					kapi1Tip=0;
				}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(asagibutonIn_GPIO_Port,asagibutonIn_Pin)==1)&&(butonKontrol==0)){
				kapi1Tip=kapi1Tip-1;
		    	if(kapi1Tip>0){
		    		kapi1Tip=1;
		    	}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(enterbutonIn_GPIO_Port,enterbutonIn_Pin)==1)&&(butonKontrol==0)){
				eepromData[8]=kapi1Tip;
				hafizaYaz=1;
			}
		}
	if (menuSayac==9){

					lcd_print(1,1,"1.KAPI AC SURESi");
					lcd_print(2,1,"Kac Saniye     ");

				itoa(kapi1AcSure, snum, 10);
				lcd_print(2,16,snum);

				if ((HAL_GPIO_ReadPin(yukaributonIn_GPIO_Port,yukaributonIn_Pin)==1)&&(butonKontrol==0)&&(kapi1Tip==0)){
					kapi1AcSure=kapi1AcSure+1;
					if(kapi1AcSure>5){
						kapi1AcSure=0;
					}
					bekle();
				}

				if ((HAL_GPIO_ReadPin(asagibutonIn_GPIO_Port,asagibutonIn_Pin)==1)&&(butonKontrol==0)&&(kapi1Tip==0)){
					kapi1AcSure=kapi1AcSure-1;
			    	if(kapi1AcSure>6){
			    		kapi1AcSure=5;
			    	}
					bekle();

				}
				if ((HAL_GPIO_ReadPin(enterbutonIn_GPIO_Port,enterbutonIn_Pin)==1)&&(butonKontrol==0)){
					eepromData[9]=kapi1AcSure;
					hafizaYaz=1;
				}
			}


	if (menuSayac==10){
			lcd_print(1,1,"2.KAT KAPI TiPi ");
			if(kapi2Tip==0){
				lcd_print(2,1,"Prudhome       ");
			}

			if(kapi2Tip==1){
				lcd_print(2,1,"Buton kontrollu");
			}

			itoa(kapi2Tip, snum, 10);
			lcd_print(2,16,snum);

			if ((HAL_GPIO_ReadPin(yukaributonIn_GPIO_Port,yukaributonIn_Pin)==1)&&(butonKontrol==0)){
				kapi2Tip=kapi2Tip+1;
				if(kapi2Tip>1){
					kapi2Tip=0;
				}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(asagibutonIn_GPIO_Port,asagibutonIn_Pin)==1)&&(butonKontrol==0)){
				kapi2Tip=kapi2Tip-1;
		    	if(kapi2Tip>0){
		    		kapi2Tip=1;
		    	}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(enterbutonIn_GPIO_Port,enterbutonIn_Pin)==1)&&(butonKontrol==0)){
				eepromData[10]=kapi2Tip;
				hafizaYaz=1;
			}
		}
	if (menuSayac==11){

				lcd_print(1,1,"2.KAPI AC SURESi");
				lcd_print(2,1,"Kac Saniye     ");


				itoa(kapi2AcSure, snum, 10);
				lcd_print(2,16,snum);

				if ((HAL_GPIO_ReadPin(yukaributonIn_GPIO_Port,yukaributonIn_Pin)==1)&&(butonKontrol==0)&&(kapi2Tip==0)){
					kapi2AcSure=kapi2AcSure+1;
					if(kapi2AcSure>5){
						kapi2AcSure=0;
					}
					bekle();
				}

				if ((HAL_GPIO_ReadPin(asagibutonIn_GPIO_Port,asagibutonIn_Pin)==1)&&(butonKontrol==0)&&(kapi2Tip==0)){
					kapi2AcSure=kapi2AcSure-1;
			    	if(kapi2AcSure>6){
			    		kapi2AcSure=5;
			    	}
					bekle();

				}
				if ((HAL_GPIO_ReadPin(enterbutonIn_GPIO_Port,enterbutonIn_Pin)==1)&&(butonKontrol==0)){
					eepromData[11]=kapi2AcSure;
					hafizaYaz=1;
				}
			}

	if (menuSayac==12){
			lcd_print(1,1,"TABLA KAPI TiPi ");
			if(kapitablaTip==0){
				lcd_print(2,1,"Prudhome       ");
			}

			if(kapitablaTip==1){
				lcd_print(2,1,"Buton kontrollu");
			}

			itoa(kapitablaTip, snum, 10);
			lcd_print(2,16,snum);

			if ((HAL_GPIO_ReadPin(yukaributonIn_GPIO_Port,yukaributonIn_Pin)==1)&&(butonKontrol==0)){
				kapitablaTip=kapitablaTip+1;
				if(kapitablaTip>1){
					kapitablaTip=0;
				}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(asagibutonIn_GPIO_Port,asagibutonIn_Pin)==1)&&(butonKontrol==0)){
				kapitablaTip=kapitablaTip-1;
		    	if(kapitablaTip>0){
		    		kapitablaTip=1;
		    	}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(enterbutonIn_GPIO_Port,enterbutonIn_Pin)==1)&&(butonKontrol==0)){
				eepromData[12]=kapitablaTip;
				hafizaYaz=1;
			}
		}

	if (menuSayac==13){

				lcd_print(1,1,"TABLA KP AC SURE");
				lcd_print(2,1,"Kac Saniye     ");

				itoa(kapiTablaAcSure, snum, 10);
				lcd_print(2,16,snum);

				if ((HAL_GPIO_ReadPin(yukaributonIn_GPIO_Port,yukaributonIn_Pin)==1)&&(butonKontrol==0)&&(kapitablaTip==0)){
					kapiTablaAcSure=kapiTablaAcSure+1;
					if(kapiTablaAcSure>5){
						kapiTablaAcSure=0;
					}
					bekle();
				}

				if ((HAL_GPIO_ReadPin(asagibutonIn_GPIO_Port,asagibutonIn_Pin)==1)&&(butonKontrol==0)&&(kapitablaTip==0)){
					kapiTablaAcSure=kapiTablaAcSure-1;
			    	if(kapiTablaAcSure>6){
			    		kapiTablaAcSure=5;
			    	}
					bekle();

				}
				if ((HAL_GPIO_ReadPin(enterbutonIn_GPIO_Port,enterbutonIn_Pin)==1)&&(butonKontrol==0)){
					eepromData[13]=kapiTablaAcSure;
					hafizaYaz=1;
				}
			}

	if (menuSayac==14){
			lcd_print(1,1,"YUKARI YAVAS LMT");
			if(yukariYavasLimit==0){
				lcd_print(2,1,"Pasif          ");
			}

			if(yukariYavasLimit==1){
				lcd_print(2,1,"Aktif          ");
			}

			itoa(yukariYavasLimit, snum, 10);
			lcd_print(2,16,snum);

			if ((HAL_GPIO_ReadPin(yukaributonIn_GPIO_Port,yukaributonIn_Pin)==1)&&(butonKontrol==0)){
				yukariYavasLimit=yukariYavasLimit+1;
				if(yukariYavasLimit>1){
					yukariYavasLimit=0;
				}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(asagibutonIn_GPIO_Port,asagibutonIn_Pin)==1)&&(butonKontrol==0)){
				yukariYavasLimit=yukariYavasLimit-1;
		    	if(yukariYavasLimit>0){
		    		yukariYavasLimit=1;
		    	}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(enterbutonIn_GPIO_Port,enterbutonIn_Pin)==1)&&(butonKontrol==0)){
				eepromData[14]=yukariYavasLimit;
				hafizaYaz=1;
			}
		}

	if (menuSayac==15){
			lcd_print(1,1,"DEVIRME-YURUYUS ");
			if(devirmeYuruyusSecim==2){

				lcd_print(2,1,"Devirme aktif  ");
			}

			if(devirmeYuruyusSecim==1){
				lcd_print(2,1,"Yuruyus aktif  ");

			}

			if(devirmeYuruyusSecim==0){
				lcd_print(2,1,"Pasif          ");

			}
			itoa(devirmeYuruyusSecim, snum, 10);
			lcd_print(2,16,snum);

			if ((HAL_GPIO_ReadPin(yukaributonIn_GPIO_Port,yukaributonIn_Pin)==1)&&(butonKontrol==0)){
				devirmeYuruyusSecim=devirmeYuruyusSecim+1;
				if(devirmeYuruyusSecim>2){
					devirmeYuruyusSecim=0;
				}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(asagibutonIn_GPIO_Port,asagibutonIn_Pin)==1)&&(butonKontrol==0)){
				devirmeYuruyusSecim=devirmeYuruyusSecim-1;
		    	if(devirmeYuruyusSecim>3){
		    		devirmeYuruyusSecim=2;
		    	}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(enterbutonIn_GPIO_Port,enterbutonIn_Pin)==1)&&(butonKontrol==0)){
				eepromData[15]=devirmeYuruyusSecim;
				if(devirmeYuruyusSecim==2||devirmeYuruyusSecim==1)
				{
					calismaSekli=0;
					eepromData[1]=calismaSekli;
				}

				if(devirmeYuruyusSecim==1){
					devirmeSilindirTipi=1;
					eepromData[18]=devirmeSilindirTipi;
				}
				hafizaYaz=1;
			}
		}
	if (menuSayac==16){

				if(devirmeYuruyusSecim==2){
					lcd_print(1,1,"DEVRM YUKARI SVC");
				}

				if(devirmeYuruyusSecim==1){
					lcd_print(1,1,"YURUYUS ILER SVC");
				}

				if(devirmeYukariIleriLimit==0){
					lcd_print(2,1,"Pasif          ");
				}

				if(devirmeYukariIleriLimit==1){
					lcd_print(2,1,"Aktif          ");
				}

				itoa(devirmeYukariIleriLimit, snum, 10);
				lcd_print(2,16,snum);

				if ((HAL_GPIO_ReadPin(yukaributonIn_GPIO_Port,yukaributonIn_Pin)==1)&&(butonKontrol==0)){
					devirmeYukariIleriLimit=devirmeYukariIleriLimit+1;
					if(devirmeYukariIleriLimit>1){
						devirmeYukariIleriLimit=0;
					}
					bekle();
				}

				if ((HAL_GPIO_ReadPin(asagibutonIn_GPIO_Port,asagibutonIn_Pin)==1)&&(butonKontrol==0)){
					devirmeYukariIleriLimit=devirmeYukariIleriLimit-1;
			    	if(devirmeYukariIleriLimit>0){
			    		devirmeYukariIleriLimit=1;
			    	}
					bekle();
				}

				if ((HAL_GPIO_ReadPin(enterbutonIn_GPIO_Port,enterbutonIn_Pin)==1)&&(butonKontrol==0)){
					eepromData[16]=devirmeYukariIleriLimit;
					hafizaYaz=1;
				}
			}

	if (menuSayac==17){
			if(devirmeYuruyusSecim==2){
				lcd_print(1,1,"DEVIRM ASAGI SVC");
			}

			if(devirmeYuruyusSecim==1){
				lcd_print(1,1,"YURUYUS GERI SVC");
			}

			if(devirmeAsagiGeriLimit==0){
				lcd_print(2,1,"Pasif          ");
			}

			if(devirmeAsagiGeriLimit==1){
				lcd_print(2,1,"Aktif          ");
			}

			itoa(devirmeAsagiGeriLimit, snum, 10);
			lcd_print(2,16,snum);

			if ((HAL_GPIO_ReadPin(yukaributonIn_GPIO_Port,yukaributonIn_Pin)==1)&&(butonKontrol==0)){
				devirmeAsagiGeriLimit=devirmeAsagiGeriLimit+1;
				if(devirmeAsagiGeriLimit>1){
					devirmeAsagiGeriLimit=0;
				}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(asagibutonIn_GPIO_Port,asagibutonIn_Pin)==1)&&(butonKontrol==0)){
				devirmeAsagiGeriLimit=devirmeAsagiGeriLimit-1;
		    	if(devirmeAsagiGeriLimit>0){
		    		devirmeAsagiGeriLimit=1;
		    	}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(enterbutonIn_GPIO_Port,enterbutonIn_Pin)==1)&&(butonKontrol==0)){
				eepromData[17]=devirmeAsagiGeriLimit;
				hafizaYaz=1;
			}
		}

	if (menuSayac==18){
			if(devirmeYuruyusSecim==1){
				lcd_print(1,1,"YURUYUS SECiLDi ");
			}
			if(devirmeYuruyusSecim==2){
			lcd_print(1,1,"DEVIRME SLN TIPI");
			}
			if(devirmeSilindirTipi==0){
				lcd_print(2,1,"Tek tesir      ");
			}

			if(devirmeSilindirTipi==1){
				lcd_print(2,1,"Cift tesir     ");
			}

			itoa(devirmeSilindirTipi, snum, 10);
			lcd_print(2,16,snum);

			if ((HAL_GPIO_ReadPin(yukaributonIn_GPIO_Port,yukaributonIn_Pin)==1)&&(butonKontrol==0)&&(devirmeYuruyusSecim==2)){
				devirmeSilindirTipi=devirmeSilindirTipi+1;
				if(devirmeSilindirTipi>1){
					devirmeSilindirTipi=0;
				}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(asagibutonIn_GPIO_Port,asagibutonIn_Pin)==1)&&(butonKontrol==0)&&(devirmeYuruyusSecim==2)){
				devirmeSilindirTipi=devirmeSilindirTipi-1;
		    	if(devirmeSilindirTipi>0){
		    		devirmeSilindirTipi=1;
		    	}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(enterbutonIn_GPIO_Port,enterbutonIn_Pin)==1)&&(butonKontrol==0)){
				eepromData[18]=devirmeSilindirTipi;
				hafizaYaz=1;
			}
		}

	if (menuSayac==19){
			lcd_print(1,1,"PLATFRM SLN TIPI");
			if(platformSilindirTipi==0){
				lcd_print(2,1,"Tek tesir      ");
			}

			if(platformSilindirTipi==1){
				lcd_print(2,1,"Cift tesir     ");
			}

			itoa(platformSilindirTipi, snum, 10);
			lcd_print(2,16,snum);

			if ((HAL_GPIO_ReadPin(yukaributonIn_GPIO_Port,yukaributonIn_Pin)==1)&&(butonKontrol==0)){
				platformSilindirTipi=platformSilindirTipi+1;
				if(platformSilindirTipi>1){
					platformSilindirTipi=0;
				}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(asagibutonIn_GPIO_Port,asagibutonIn_Pin)==1)&&(butonKontrol==0)){
				platformSilindirTipi=platformSilindirTipi-1;
		    	if(platformSilindirTipi>0){
		    		platformSilindirTipi=1;
		    	}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(enterbutonIn_GPIO_Port,enterbutonIn_Pin)==1)&&(butonKontrol==0)){
				eepromData[19]=platformSilindirTipi;
				hafizaYaz=1;
			}
		}

	if (menuSayac==20){
			lcd_print(1,1,"YUKARI VALF SURE");
			if(yukariValfTmr>=0){
				lcd_print(2,1,"Kac Saniye     ");
			}

			itoa(yukariValfTmr, snum, 10);
			lcd_print(2,16,snum);

			if ((HAL_GPIO_ReadPin(yukaributonIn_GPIO_Port,yukaributonIn_Pin)==1)&&(butonKontrol==0)){
				yukariValfTmr=yukariValfTmr+1;
				if(yukariValfTmr>5){
					yukariValfTmr=0;
				}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(asagibutonIn_GPIO_Port,asagibutonIn_Pin)==1)&&(butonKontrol==0)){
				yukariValfTmr=yukariValfTmr-1;
		    	if(yukariValfTmr>6){
		    		yukariValfTmr=5;
		    	}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(enterbutonIn_GPIO_Port,enterbutonIn_Pin)==1)&&(butonKontrol==0)){
				eepromData[20]=yukariValfTmr;
				hafizaYaz=1;
			}
		}

	if (menuSayac==21){
			lcd_print(1,1,"ASAGI VALF SURE ");
			if(asagiValfTmr>=0){
				lcd_print(2,1,"Kac Saniye     ");
			}

			itoa(asagiValfTmr, snum, 10);
			lcd_print(2,16,snum);

			if ((HAL_GPIO_ReadPin(yukaributonIn_GPIO_Port,yukaributonIn_Pin)==1)&&(butonKontrol==0)){
				asagiValfTmr=asagiValfTmr+1;
				if(asagiValfTmr>5){
					asagiValfTmr=0;
				}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(asagibutonIn_GPIO_Port,asagibutonIn_Pin)==1)&&(butonKontrol==0)){
				asagiValfTmr=asagiValfTmr-1;
		    	if(asagiValfTmr>6){
		    		asagiValfTmr=5;
		    	}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(enterbutonIn_GPIO_Port,enterbutonIn_Pin)==1)&&(butonKontrol==0)){
				eepromData[21]=asagiValfTmr;
				hafizaYaz=1;
			}
		}

	if (menuSayac==22){
			if(devirmeYuruyusSecim==2){
				lcd_print(1,1,"DVRM YKR VLF SN ");
			}

			if(devirmeYuruyusSecim==1){
				lcd_print(1,1,"iLERi VALF SURE ");
			}

			if(devirmeYukariIleriTmr>=0){
				lcd_print(2,1,"Kac Saniye     ");
			}

			itoa(devirmeYukariIleriTmr, snum, 10);
			lcd_print(2,16,snum);

			if ((HAL_GPIO_ReadPin(yukaributonIn_GPIO_Port,yukaributonIn_Pin)==1)&&(butonKontrol==0)){
				devirmeYukariIleriTmr=devirmeYukariIleriTmr+1;
				if(devirmeYukariIleriTmr>5){
					devirmeYukariIleriTmr=0;
				}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(asagibutonIn_GPIO_Port,asagibutonIn_Pin)==1)&&(butonKontrol==0)){
				devirmeYukariIleriTmr=devirmeYukariIleriTmr-1;
		    	if(devirmeYukariIleriTmr>6){
		    		devirmeYukariIleriTmr=5;
		    	}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(enterbutonIn_GPIO_Port,enterbutonIn_Pin)==1)&&(butonKontrol==0)){
				eepromData[22]=devirmeYukariIleriTmr;
				hafizaYaz=1;
			}
		}

	if (menuSayac==23){
			if(devirmeYuruyusSecim==2){
				lcd_print(1,1,"DVRM ASG VALF SN");
			}
			if(devirmeYuruyusSecim==1){
				lcd_print(1,1,"GERi VALF SURE  ");
			}

			if(devirmeAsagiGeriTmr>=0){
				lcd_print(2,1,"Kac Saniye     ");
			}

			itoa(devirmeAsagiGeriTmr, snum, 10);
			lcd_print(2,16,snum);

			if ((HAL_GPIO_ReadPin(yukaributonIn_GPIO_Port,yukaributonIn_Pin)==1)&&(butonKontrol==0)){
				devirmeAsagiGeriTmr=devirmeAsagiGeriTmr+1;
				if(devirmeAsagiGeriTmr>5){
					devirmeAsagiGeriTmr=0;
				}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(asagibutonIn_GPIO_Port,asagibutonIn_Pin)==1)&&(butonKontrol==0)){
				devirmeAsagiGeriTmr=devirmeAsagiGeriTmr-1;
		    	if(devirmeAsagiGeriTmr>6){
		    		devirmeAsagiGeriTmr=5;
		    	}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(enterbutonIn_GPIO_Port,enterbutonIn_Pin)==1)&&(butonKontrol==0)){
				eepromData[23]=devirmeAsagiGeriTmr;
				hafizaYaz=1;
			}
		}

	if (menuSayac==24){
			lcd_print(1,1,"CALiSMA SURESi  ");
			if(makineCalismaTmr>99){

				lcd_print(2,1,"Kac Saniye   ");
				itoa(makineCalismaTmr, snum, 10);
				lcd_print(2,14,snum);

			}
			if((makineCalismaTmr>10)&&(makineCalismaTmr<=99)){
				lcd_print(2,1,"Kac Saniye    ");

			itoa(makineCalismaTmr, snum, 10);
			lcd_print(2,15,snum);
			}
			if(makineCalismaTmr<=9)
			{
				lcd_print(2,1,"Kac Saniye     ");

				itoa(makineCalismaTmr, snum, 10);
				lcd_print(2,16,snum);
			}

			if ((HAL_GPIO_ReadPin(yukaributonIn_GPIO_Port,yukaributonIn_Pin)==1)&&(butonKontrol==0)){
				makineCalismaTmr=makineCalismaTmr+1;
				if(makineCalismaTmr>180){
					makineCalismaTmr=0;
				}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(asagibutonIn_GPIO_Port,asagibutonIn_Pin)==1)&&(butonKontrol==0)){
				makineCalismaTmr=makineCalismaTmr-1;
		    	if(makineCalismaTmr>181){
		    		makineCalismaTmr=180;
		    	}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(enterbutonIn_GPIO_Port,enterbutonIn_Pin)==1)&&(butonKontrol==0)){
				eepromData[24]=makineCalismaTmr;
				hafizaYaz=1;
			}
		}

	if (menuSayac==25){
			lcd_print(1,1,"BUZZER          ");
			if(buzzer==0){
				lcd_print(2,1,"Pasif          ");
			}

			if(buzzer==1){
				lcd_print(2,1,"Aktif          ");
			}

			itoa(buzzer, snum, 10);
			lcd_print(2,16,snum);

			if ((HAL_GPIO_ReadPin(yukaributonIn_GPIO_Port,yukaributonIn_Pin)==1)&&(butonKontrol==0)){
				buzzer=buzzer+1;
				if(buzzer>1){
					buzzer=0;
				}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(asagibutonIn_GPIO_Port,asagibutonIn_Pin)==1)&&(butonKontrol==0)){
				buzzer=buzzer-1;
		    	if(buzzer>0){
		    		buzzer=1;
		    	}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(enterbutonIn_GPIO_Port,enterbutonIn_Pin)==1)&&(butonKontrol==0)){
				eepromData[25]=buzzer;
				hafizaYaz=1;
			}
		}

	if (menuSayac==26){
			lcd_print(1,1,"DEMO MODU       ");
			if(demoMode==0){
				lcd_print(2,1,"Pasif          ");
			}

			if(demoMode==1){
				lcd_print(2,1,"Aktif          ");
			}

			itoa(demoMode, snum, 10);
			lcd_print(2,16,snum);

			if ((HAL_GPIO_ReadPin(yukaributonIn_GPIO_Port,yukaributonIn_Pin)==1)&&(butonKontrol==0)){
				demoMode=demoMode+1;
				if(demoMode>1){
					demoMode=0;
				}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(asagibutonIn_GPIO_Port,asagibutonIn_Pin)==1)&&(butonKontrol==0)){
				demoMode=demoMode-1;
		    	if(demoMode>0){
		    		demoMode=1;
		    	}
				bekle();
			}

			if ((HAL_GPIO_ReadPin(enterbutonIn_GPIO_Port,enterbutonIn_Pin)==1)&&(butonKontrol==0)){
				eepromData[26]=demoMode;
				hafizaYaz=1;
			}
		}

	if (menuSayac==27){
		lcd_print(1,1," MENUDEN CIKIS  ");
		lcd_print(2,1,"ENTER'A BASINIZ ");

		if (HAL_GPIO_ReadPin(enterbutonIn_GPIO_Port,enterbutonIn_Pin)==1){
			menuGiris=0;
			lcd_clear();
			NVIC_SystemReset();
		}
		}
}

void i2cTest(void)
{
	GPIO_InitTypeDef strutturaGPIO = {0};

	hi2c1.Instance->CR1 &= ~(1 << 0);
	HAL_I2C_DeInit(&hi2c1);

	strutturaGPIO.Pin = GPIO_PIN_6|GPIO_PIN_7;
	strutturaGPIO.Mode = GPIO_MODE_OUTPUT_OD;
	strutturaGPIO.Pull = GPIO_PULLUP;
	strutturaGPIO.Speed = GPIO_SPEED_HIGH;
    HAL_GPIO_Init(GPIOB, &strutturaGPIO);

    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET);

    //lcd_print(1,1," test-1         ");
    //lcd_print(2,1,"SCL and SDL LOW ");
    HAL_Delay(10);
	while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6) != GPIO_PIN_SET && HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_7) != GPIO_PIN_SET){

	}

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET);
  //  lcd_print(1,1," test-2         ");
  //  lcd_print(2,1,"SCL and SDL HIGH");
    HAL_Delay(10);
	while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_7) == GPIO_PIN_SET){

	}

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);
  //  lcd_print(1,1," test-3         ");
  //  lcd_print(2,1,"SCL   ----- HIGH");
    HAL_Delay(10);
	while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6) == GPIO_PIN_SET){

	}

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET);
  //  lcd_print(1,1," test-4         ");
 //   lcd_print(2,1,"SCL   ----- HIGH");
    HAL_Delay(10);
	while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6) != GPIO_PIN_SET){

	}
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET);
   // lcd_print(1,1," test-5         ");
   // lcd_print(2,1,"SCL   ----- HIGH");
    HAL_Delay(10);
	while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_7) != GPIO_PIN_SET){

	}

	strutturaGPIO.Pin = GPIO_PIN_6|GPIO_PIN_7;
	strutturaGPIO.Mode = GPIO_MODE_AF_OD;
	strutturaGPIO.Pull = GPIO_PULLUP;
	strutturaGPIO.Speed = GPIO_SPEED_HIGH;
    HAL_GPIO_Init(GPIOB, &strutturaGPIO);

	hi2c1.Instance->CR1 |= 1 << 15;

	hi2c1.Instance->CR1 &= ~(1 << 15);

	hi2c1.Instance->CR1 |= 1 << 0;

	HAL_I2C_Init(&hi2c1);

}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) //------timer kesmesinde islem yapmak için
{
	  millis=millis+1;
	  //millis1=millis1+1;
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */
  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_CAN_Init();
  MX_I2C1_Init();
  MX_TIM1_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
  WiFi_Init();

  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET);
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET);
  HAL_Delay(10);
  lcd_init();
  HAL_Delay(10);

  while(HAL_I2C_GetError(&hi2c1) == HAL_I2C_ERROR_AF);
  while (HAL_I2C_GetState(&hi2c1) != HAL_I2C_STATE_READY){
	  HAL_Delay(10);
	  lcd_print(2,1,"I2C.............");
	  HAL_Delay(250);
  }

  HAL_GPIO_WritePin(motorOut_GPIO_Port, motorOut_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(motorIkinciHizOut_GPIO_Port, motorIkinciHizOut_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(yukariValfOut_GPIO_Port, yukariValfOut_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(asagiValfOut_GPIO_Port, asagiValfOut_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(yavaslamaValfOut_GPIO_Port, yavaslamaValfOut_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(devirmeYukariIleriOut_GPIO_Port, devirmeYukariIleriOut_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(devirmeAsagiGeriOut_GPIO_Port, devirmeAsagiGeriOut_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(kapi1Out_GPIO_Port, kapi1Out_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(kapi2Out_GPIO_Port, kapi2Out_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(tablaKapiOut_GPIO_Port, tablaKapiOut_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(buzzerOut_GPIO_Port, buzzerOut_Pin, GPIO_PIN_RESET);


  HAL_TIM_Base_Start_IT(&htim1);
  i2cTest();
  lcd_print(1,1,"Desing By R.CANB");
  lcd_print(2,1,"ONDTECH ESP CONT");
  HAL_Delay(2000);



    HAL_I2C_Mem_Read(&hi2c1,0xA0,0,63,eepromData,63,1000);

	  acilStop1=eepromData[0];
	  kaydedilenDeger =eepromData[3];
	  calismaSekli=eepromData[1];
	  emniyetCercevesi=eepromData[2];
	  yavaslamaLimit =eepromData[4];
	  altLimit=eepromData[5];
	  basincSalteri=eepromData[6];
	  kapiSivici=eepromData[7];
	  kapi1Tip=eepromData[8];
	  kapi1AcSure=eepromData[9];
	  kapi2Tip=eepromData[10];
	  kapi2AcSure=eepromData[11];
	  kapitablaTip=eepromData[12];
	  kapiTablaAcSure=eepromData[13];
	  yukariYavasLimit=eepromData[14];
	  devirmeYuruyusSecim=eepromData[15];
	  devirmeYukariIleriLimit=eepromData[16];
	  devirmeAsagiGeriLimit=eepromData[17];
	  devirmeSilindirTipi=eepromData[18];
	  platformSilindirTipi=eepromData[19];
	  yukariValfTmr=eepromData[20];
	  asagiValfTmr=eepromData[21];
	  devirmeYukariIleriTmr=eepromData[22];
	  devirmeAsagiGeriTmr=eepromData[23];
	  makineCalismaTmr=eepromData[24];
	  buzzer=eepromData[25];
	  demoMode=eepromData[26];
	  calismaSayisi=eepromData[27];
	  calismaSayisi1=eepromData[28];
	  calismaSayisi10=eepromData[29];
	  calismaSayisi100=eepromData[30];
	  calismaSayisi1000=eepromData[31];
	  calismaSayisi10000=eepromData[32];

	  if(calismaSayisi10000>9){
		  calismaSayisi10000=0;
	  }
	  if(calismaSayisi1000>9){
		  calismaSayisi1000=0;
	  }
	  if(calismaSayisi100>9){
		  calismaSayisi100=0;
	  }
	  if(calismaSayisi10>9){
		  calismaSayisi10=0;
	  }
	  if(calismaSayisi1>9){
		  calismaSayisi1=0;
	  }
	  HAL_Delay(1000);

  /* USER CODE END 2 */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 128);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* Start scheduler */
  osKernelStart();
  /* We should never get here as control is now taken by the scheduler */
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	  while (1)
	   {

	   }
  /* USER CODE END 3 */
}

void WiFi_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  // GPIOA Clock Enable
  __HAL_RCC_GPIOA_CLK_ENABLE();

  // USART2 GPIO Configuration
  // PA2 ------> USART2_TX
  // PA3 ------> USART2_RX
  GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_3;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  //GPIO_InitStruct.Alternate = GPIO_AF7_USART2;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  // USART2 initialization
  MX_USART1_UART_Init();
}

void WiFi_Connect(void)
{
  char cmd[100];

  sprintf(cmd, "AT+RST\r\n");
  HAL_UART_Transmit(&huart1, (uint8_t*)cmd, strlen(cmd), HAL_MAX_DELAY);
  HAL_Delay(1000);

  sprintf(cmd, "AT+CWMODE=1\r\n");
  HAL_UART_Transmit(&huart1, (uint8_t*)cmd, strlen(cmd), HAL_MAX_DELAY);
  HAL_Delay(500);

  //HAL_UART_Transmit(&huart1, (uint8_t*)("AT+CWJAP=\""+ssid+"\",\""+password+"\"\r\n"), strlen("AT+CWJAP=\""+ssid+"\",\""+password+"\"\r\n"), HAL_MAX_DELAY);
  //HAL_UART_Transmit(&huart1, (uint8_t*) ("AT+CWJAP=\""+ssid+"\",\""+password+"\"\r\n"), strlen("AT+CWJAP=\""ssid));
  sprintf(cmd, "AT+CWJAP=\"%s\",\"%s\"\r\n", wifi_ssid, wifi_password);
  HAL_UART_Transmit(&huart1, (uint8_t*)cmd, strlen(cmd), HAL_MAX_DELAY);
  HAL_Delay(5000);


}

void Send_GET_Request(char* server, char* api, uint8_t led)
{
  char cmd[200];
  sprintf(cmd, "AT+CIPSTART=\"TCP\",\"%s\",80\r\n", server);
  HAL_UART_Transmit(&huart1, (uint8_t*)cmd, strlen(cmd), HAL_MAX_DELAY);
  HAL_Delay(1000);

  sprintf(cmd, "AT+CIPSEND=%d\r\n", 40);
  HAL_UART_Transmit(&huart1, (uint8_t*)cmd, strlen(cmd), HAL_MAX_DELAY);
  HAL_Delay(1000);

  sprintf(cmd, "GET %s?led=%d HTTP/1.1\r\nHost: %s\r\n\r\n", api, led, server);
  HAL_UART_Transmit(&huart1, (uint8_t*)cmd, strlen(cmd), HAL_MAX_DELAY);
  HAL_Delay(1000);

  sprintf(cmd, "AT+CIPCLOSE\r\n");
  HAL_UART_Transmit(&huart1, (uint8_t*)cmd, strlen(cmd), HAL_MAX_DELAY);
  HAL_Delay(1000);
}

void dataTask(void *pvParameters) {
	while(1) {
		WiFi_Connect();
	}
}

void programTask(void *pvParameters) {
	while(1) {
		if((HAL_GPIO_ReadPin(ileributonIn_GPIO_Port,ileributonIn_Pin)==0)&&(HAL_GPIO_ReadPin(geributonIn_GPIO_Port,geributonIn_Pin)==0)&&(HAL_GPIO_ReadPin(yukaributonIn_GPIO_Port,yukaributonIn_Pin)==0)&&(HAL_GPIO_ReadPin(asagibutonIn_GPIO_Port,asagibutonIn_Pin)==0)&&(HAL_GPIO_ReadPin(enterbutonIn_GPIO_Port,enterbutonIn_Pin)==0)&&(HAL_GPIO_ReadPin(kapiacIn_GPIO_Port, kapiacIn_Pin)==0)&&(HAL_GPIO_ReadPin(ustkapiacIn_GPIO_Port, ustkapiacIn_Pin)==0)&&(HAL_GPIO_ReadPin(tablakapiacIn_GPIO_Port, tablakapiacIn_Pin)==0))
				   {
					   butonKontrol=0;
				   }

				  if(hafizaYaz==1){
					  while(HAL_I2C_GetError(&hi2c1) == HAL_I2C_ERROR_AF);
					  while (HAL_I2C_GetState(&hi2c1) != HAL_I2C_STATE_READY){

					  }
					  HAL_I2C_Mem_Write(&hi2c1,0xA0,0,63,eepromData,63,3000);
					  HAL_Delay(5);
					  hafizaYaz=0;
					  lcd_print(2,1,"Data yazildi    ");
					  HAL_Delay(1000);
					  lcd_clear();
				  }

				  if((hafizaOku==0)&&(HAL_I2C_GetState(&hi2c1) == HAL_I2C_STATE_READY)){
					  if(ilkOkuma==0){
						  lcd_print(1,1,"    **EEPROM**  ");
						  lcd_print(2,1,"Data Okunuyor...");
						  HAL_Delay(1000);
						  while(HAL_I2C_GetError(&hi2c1) == HAL_I2C_ERROR_AF);
						  while (HAL_I2C_GetState(&hi2c1) != HAL_I2C_STATE_READY){
							  HAL_Delay(1000);
						  }
						  lcd_print(2,1,"Data Okundu.    ");
						  ilkOkuma=1;
					  }
					  else{
						  lcd_print(2,1,"Deger Kaydedildi");
						  lcd_clear();
					  }

					  HAL_I2C_Mem_Read(&hi2c1,0xA0,0,63,eepromData,63,3000);
					  HAL_Delay(1000);

					  acilStop1=eepromData[0];
					  kaydedilenDeger=eepromData[3];
					  calismaSekli=eepromData[1];
					  emniyetCercevesi=eepromData[2];
					  yavaslamaLimit=eepromData[4];
					  altLimit=eepromData[5];
					  basincSalteri=eepromData[6];
					  kapiSivici=eepromData[7];
					  kapi1Tip=eepromData[8];
					  kapi1AcSure=eepromData[9];
					  kapi2Tip=eepromData[10];
					  kapi2AcSure=eepromData[11];
					  kapitablaTip=eepromData[12];
					  kapiTablaAcSure=eepromData[13];
					  yukariYavasLimit=eepromData[14];
					  devirmeYuruyusSecim=eepromData[15];
					  devirmeYukariIleriLimit=eepromData[16];
					  devirmeAsagiGeriLimit=eepromData[17];
					  devirmeSilindirTipi=eepromData[18];
					  platformSilindirTipi=eepromData[19];
					  yukariValfTmr=eepromData[20];
					  asagiValfTmr=eepromData[21];
					  devirmeYukariIleriTmr=eepromData[22];
					  devirmeAsagiGeriTmr=eepromData[23];
					  makineCalismaTmr=eepromData[24];
					  buzzer=eepromData[25];
					  demoMode=eepromData[26];
					  calismaSayisi=eepromData[27];
					  calismaSayisi1=eepromData[28];
					  calismaSayisi10=eepromData[29];
					  calismaSayisi100=eepromData[30];
					  calismaSayisi1000=eepromData[31];
					  calismaSayisi10000=eepromData[32];

					  if(calismaSayisi10000>9){
						  calismaSayisi10000=0;
					  }
					  if(calismaSayisi1000>9){
						  calismaSayisi1000=0;
					  }
					  if(calismaSayisi100>9){
						  calismaSayisi100=0;
					  }
					  if(calismaSayisi10>9){
						  calismaSayisi10=0;
					  }
					  if(calismaSayisi1>9){
						  calismaSayisi1=0;
					  }

					  hafizaOku=1;
					  lcd_clear();
				  }

				  if((menuGiris==0)&&(mesajYazildi==0)&&(demoMode==0)){
					  lcd_print(1,1,"ANA SAYFA       ");
					  mesajYazildi=1;
				  }

				  if ((menuGiris==0) && (HAL_GPIO_ReadPin(yukaributonIn_GPIO_Port,yukaributonIn_Pin)==1) && (HAL_GPIO_ReadPin(asagibutonIn_GPIO_Port,asagibutonIn_Pin)==1))
				  {
					  menuGiris=1;
					  lcd_clear();
				  }
				  if(menuGiris==1){
					  menu();
				  }
				  HAL_GPIO_TogglePin(buzzerOut_GPIO_Port, buzzerOut_Pin);
		/* GİRİLEN PARAMETRELERE GÖRE AYARLARIN YAPILMASI*/
				  if((acilStop1==0)||(hataVar==0)){

				  if(acilStop1==0){

					  stopVar=1;
				  }
			/*	  if(acilStop1==1){

					  stopVar=HAL_GPIO_ReadPin(acilstopIn_GPIO_Port, acilstopIn_Pin);
				  }
				  if(acilStop1==2){

					  stopVar=(HAL_GPIO_ReadPin(acilStop1In_GPIO_Port, acilStop1In_Pin))&&(HAL_GPIO_ReadPin(acilStop2In_GPIO_Port, acilStop2In_Pin));
				  }
				  if(acilStop1==3){

					  stopVar=(HAL_GPIO_ReadPin(acilStop1In_GPIO_Port, acilStop1In_Pin))
							  &&(HAL_GPIO_ReadPin(acilStop2In_GPIO_Port, acilStop2In_Pin))
							  &&(HAL_GPIO_ReadPin(acilStop3In_GPIO_Port, acilStop3In_Pin));
				  }

				  }

				  */
				  else{
					  stopVar=0;
				  }

				  }

				  /******** Bas gönder ***********/

				  if((calismaSekli==1)&&(yukarimotorcalisiyor==1)&&(devirmeYuruyusSecim==0)){

					  basgondercalisyukari=1;
				  }
				  else if(yukarimotorcalisiyor==0)

					  basgondercalisyukari=0;

				  if((calismaSekli==1)&&(asagivalfcalisiyor==1)&&(devirmeYuruyusSecim==0)){

					  basgondercalisasagi=1;
				  }

				  else if((asagivalfcalisiyor==0)&&(devirmeYuruyusSecim==0))
					  basgondercalisasagi=0;

				  /******** Bas gönder ***********/

				  if(kapiSivici==0){

					  kapiSivicVar=1;
				  }

				  if(kapiSivici==1){

					kapiSivicVar=HAL_GPIO_ReadPin(kapiSiviciIn_GPIO_Port, kapiSiviciIn_Pin);
				  }

				  if(kapiSivici==2){

					  kapiSivicVar=HAL_GPIO_ReadPin(tablakapisiviciIn_GPIO_Port, tablakapisiviciIn_Pin);
				  }

				  if(kapiSivici==3){

					  kapiSivicVar=(HAL_GPIO_ReadPin(kapiSiviciIn_GPIO_Port, kapiSiviciIn_Pin))&&(HAL_GPIO_ReadPin(tablakapisiviciIn_GPIO_Port, tablakapisiviciIn_Pin));
				  }

		/* PARAMETRELERE GÖRE ÇIKI�?LARIN AYARLANMASI*/
				/*MOTOR CALISIYOR*/
				  if(demoMode==0){
				  if(((yukarimotorcalisiyor)||(devmotoryukaricalisiyor)||((asagivalfcalisiyor)&&(platformSilindirTipi==1))||((devmotorasagicalisiyor)&&(devirmeSilindirTipi)==1))&&(stopVar)&&(kapiSivicVar))

				  {
					  HAL_GPIO_WritePin(motorOut_GPIO_Port, motorOut_Pin, GPIO_PIN_SET);
					  motorcalisiyor=1;
				  }
				  else
				  {
					  HAL_GPIO_WritePin(motorOut_GPIO_Port, motorOut_Pin, GPIO_PIN_RESET);
					  motorcalisiyor=0;
				  }

				  /*YUKARI ÇALI�?MA*/


				  if((menuGiris==0) && (stopVar) && (kapiSivicVar)																			/********* motor calısması ***********/
									&& ((HAL_GPIO_ReadPin(yukaristartIn_GPIO_Port, yukaristartIn_Pin)==1)||(basgondercalisyukari))
									&& (HAL_GPIO_ReadPin(ustlimitIn_GPIO_Port, ustlimitIn_Pin)==1)
									&& ((HAL_GPIO_ReadPin(basincSalteriIn_GPIO_Port, basincSalteriIn_Pin)==1)||!(basincSalteri))
									&& (((HAL_GPIO_ReadPin(asagiStartIn_GPIO_Port, asagiStartIn_Pin)==0)
									&& (HAL_GPIO_ReadPin(devirmeyukariileriIn_GPIO_Port, devirmeyukariileriIn_Pin)==0)
									&& (HAL_GPIO_ReadPin(devirmeasagigeriIn_GPIO_Port, devirmeasagigeriIn_Pin)==0))||(yukarimotorcalisiyor))
									&& (asagivalfcalisiyor==0)
									&& (devmotoryukaricalisiyor==0)
									&& (devmotorasagicalisiyor==0))
				  {
					  yukarimotorcalisiyor=1;
				  }
				  else
				  {
					  yukarimotorcalisiyor=0;
				  }

				  if((yukarimotorcalisiyor==1)&&(((HAL_GPIO_ReadPin(yukariYavaslamaLimitIn_GPIO_Port, yukariYavaslamaLimitIn_Pin)==0))&&(yukariYavasLimit))){	/* ikinci hız */

					  HAL_GPIO_WritePin(motorIkinciHizOut_GPIO_Port, motorIkinciHizOut_Pin, GPIO_PIN_SET);
				  }
				  else
					  HAL_GPIO_WritePin(motorIkinciHizOut_GPIO_Port, motorIkinciHizOut_Pin, GPIO_PIN_RESET);
				  if(yukarimotorcalisiyor && (devirmeYuruyusSecim==1 || devirmeYuruyusSecim==2))

				  {
					  HAL_GPIO_WritePin(yukariValfOut_GPIO_Port, yukariValfOut_Pin, GPIO_PIN_SET);
				  }
				  else
					  HAL_GPIO_WritePin(yukariValfOut_GPIO_Port, yukariValfOut_Pin, GPIO_PIN_RESET);


				  //Ond safety

				  if(emniyetCercevesi==0){

					  cerceveVar=1;
				  }

				  if((emniyetCercevesi==1)&&(HAL_GPIO_ReadPin(ecercevesiIn_GPIO_Port, ecercevesiIn_Pin))&&(HAL_GPIO_ReadPin(yukaristartIn_GPIO_Port, yukaristartIn_Pin))){

					  cerceveVar=1;
				  }
				  else if((emniyetCercevesi==1)&&(HAL_GPIO_ReadPin(ecercevesiIn_GPIO_Port, ecercevesiIn_Pin)==0)){

					  cerceveVar=0;
				  }



				  //Asagi calisma

				  if((menuGiris==0)&& (stopVar)&& (kapiSivicVar)
								   && ((HAL_GPIO_ReadPin(asagiStartIn_GPIO_Port, asagiStartIn_Pin)==1)||(basgondercalisasagi))
								   && (cerceveVar)
								   && ((HAL_GPIO_ReadPin(altlimitIn_GPIO_Port, altlimitIn_Pin)==1)||!(altLimit))
								   && (((HAL_GPIO_ReadPin(yukaristartIn_GPIO_Port, yukaristartIn_Pin)==0)
								   && (HAL_GPIO_ReadPin(devirmeyukariileriIn_GPIO_Port, devirmeyukariileriIn_Pin)==0)
								   && (HAL_GPIO_ReadPin(devirmeasagigeriIn_GPIO_Port, devirmeasagigeriIn_Pin)==0))||(asagivalfcalisiyor))
								   && (yukarimotorcalisiyor==0)
					  	  	  	   && (devmotoryukaricalisiyor==0)
					  			   && (devmotorasagicalisiyor==0))
				  {
					  HAL_GPIO_WritePin(asagiValfOut_GPIO_Port, asagiValfOut_Pin, GPIO_PIN_SET);
					  asagivalfcalisiyor=1;
				  }
				  else
				  {
					  HAL_GPIO_WritePin(asagiValfOut_GPIO_Port, asagiValfOut_Pin, GPIO_PIN_RESET);
					  asagivalfcalisiyor=0;
				  }


				  // asagi valf timer calisması

				  if((asagivalfcalisiyor==1)&&(HAL_GPIO_ReadPin(asagiStartIn_GPIO_Port, asagiStartIn_Pin)==0)&&(stopVar)&&(kapiSivicVar)&&(cerceveVar)&&(butonKontrol2==0)){

					  timer2=millis;
					  butonKontrol2=1;
				  }


				  if((((millis-timer2 >= asagiValfTmr)&&(butonKontrol2==1))||((stopVar==0)||(kapiSivicVar==0)||(cerceveVar==0))))
				  {
					  HAL_GPIO_WritePin(asagiValfOut_GPIO_Port, asagiValfOut_Pin, GPIO_PIN_RESET);
					  asagivalfcalisiyor=0;
					  butonKontrol2=0;

				  }

				  //yavaslama

				  if((asagivalfcalisiyor==1)&&(((HAL_GPIO_ReadPin(yavaslamaLimitIn_GPIO_Port, yavaslamaLimitIn_Pin)==1))&&(yavaslamaLimit))){	/* ikinci hız */

					  HAL_GPIO_WritePin(yavaslamaValfOut_GPIO_Port, yavaslamaValfOut_Pin, GPIO_PIN_SET);
				  }
				  else
					  HAL_GPIO_WritePin(yavaslamaValfOut_GPIO_Port, yavaslamaValfOut_Pin, GPIO_PIN_RESET);

				  /*DEVİRME BAaslangic*/

				  if((menuGiris==0)
						  && ((devirmeYuruyusSecim==1)||(devirmeYuruyusSecim==2))
						  && (stopVar) && (kapiSivicVar)
						  && (HAL_GPIO_ReadPin(devirmeyukariileriIn_GPIO_Port, devirmeyukariileriIn_Pin))
						  && ((HAL_GPIO_ReadPin(devirmeYukariLimitIn_GPIO_Port, devirmeYukariLimitIn_Pin)==1)||!(devirmeYukariIleriLimit))
						  && (((HAL_GPIO_ReadPin(devirmeasagigeriIn_GPIO_Port, devirmeasagigeriIn_Pin)==0)
						  && (HAL_GPIO_ReadPin(yukaristartIn_GPIO_Port, yukaristartIn_Pin)==0)
						  && (HAL_GPIO_ReadPin(asagiStartIn_GPIO_Port, asagiStartIn_Pin)==0))||(devmotoryukaricalisiyor))
						  && (yukarimotorcalisiyor==0)
						  && (asagivalfcalisiyor==0)
						  && (devmotorasagicalisiyor==0))

				  {
					   HAL_GPIO_WritePin(devirmeYukariIleriOut_GPIO_Port, devirmeYukariIleriOut_Pin, GPIO_PIN_SET);
					   devmotoryukaricalisiyor=1;
				  }

				  else
				  {
					  HAL_GPIO_WritePin(devirmeYukariIleriOut_GPIO_Port, devirmeYukariIleriOut_Pin, GPIO_PIN_RESET);
					  devmotoryukaricalisiyor=0;
				  }

				  if((menuGiris==0)
						  && ((devirmeYuruyusSecim==1)||(devirmeYuruyusSecim==2))
						  && (stopVar) && (kapiSivicVar)
						  && (HAL_GPIO_ReadPin(devirmeasagigeriIn_GPIO_Port, devirmeasagigeriIn_Pin))
						  && ((HAL_GPIO_ReadPin(devirmeAsagiLimitIn_GPIO_Port, devirmeAsagiLimitIn_Pin)==1)||!(devirmeAsagiGeriLimit))
						  && (((HAL_GPIO_ReadPin(devirmeyukariileriIn_GPIO_Port, devirmeyukariileriIn_Pin)==0)
						  && (HAL_GPIO_ReadPin(yukaristartIn_GPIO_Port, yukaristartIn_Pin)==0)
						  && (HAL_GPIO_ReadPin(asagiStartIn_GPIO_Port, asagiStartIn_Pin)==0))||(devmotorasagicalisiyor))
						  && (yukarimotorcalisiyor==0)
						  && (asagivalfcalisiyor==0)
						  && (devmotoryukaricalisiyor==0))

				  {
					   HAL_GPIO_WritePin(devirmeAsagiGeriOut_GPIO_Port, devirmeAsagiGeriOut_Pin, GPIO_PIN_SET);
					   devmotorasagicalisiyor=1;
				  }

				  else
				  {
					  HAL_GPIO_WritePin(devirmeAsagiGeriOut_GPIO_Port, devirmeAsagiGeriOut_Pin, GPIO_PIN_RESET);
					  devmotorasagicalisiyor=0;
				  }


				  //kapi 1 kontrol


				  if((kapi1Tip==0)&&((kapiSivici==1)||(kapiSivici==3))&&(HAL_GPIO_ReadPin(kapiacIn_GPIO_Port, kapiacIn_Pin)==1)&&(butonKontrol==0))
				  {

					  HAL_GPIO_WritePin(kapi1Out_GPIO_Port, kapi1Out_Pin, GPIO_PIN_SET);
					  timer = millis;
					  bekle();
				  }

				  if((millis-timer >= kapi1AcSure))
				  {
					  HAL_GPIO_WritePin(kapi1Out_GPIO_Port, kapi1Out_Pin, GPIO_PIN_RESET);
				  }

				  if((kapi1Tip==1)&&((kapiSivici==1)||(kapiSivici==3))&&(HAL_GPIO_ReadPin(kapiacIn_GPIO_Port, kapiacIn_Pin)==1))
				  {
					  HAL_GPIO_WritePin(kapi1Out_GPIO_Port, kapi1Out_Pin, GPIO_PIN_SET);
				  }

				  else if((kapi1Tip==1)&&((kapiSivici==1)||(kapiSivici==3)))
				  {
					  HAL_GPIO_WritePin(kapi1Out_GPIO_Port, kapi1Out_Pin, GPIO_PIN_RESET);
				  }


				    //kapi2 kontrol


				  if((kapi2Tip==0)&&((kapiSivici==1)||(kapiSivici==3))&&(HAL_GPIO_ReadPin(ustkapiacIn_GPIO_Port, ustkapiacIn_Pin)==1)&&(butonKontrol==0))
				  {

					  HAL_GPIO_WritePin(kapi2Out_GPIO_Port, kapi2Out_Pin, GPIO_PIN_SET);
					  timer = millis;
					  bekle();
				  }

				  if((millis-timer >= kapi2AcSure))
				  {
					  HAL_GPIO_WritePin(kapi2Out_GPIO_Port, kapi2Out_Pin, GPIO_PIN_RESET);
				  }

				  if((kapi2Tip==1)&&((kapiSivici==1)||(kapiSivici==3))&&(HAL_GPIO_ReadPin(ustkapiacIn_GPIO_Port, ustkapiacIn_Pin)==1))
				  {
					  HAL_GPIO_WritePin(kapi2Out_GPIO_Port, kapi2Out_Pin, GPIO_PIN_SET);
				  }

				  else if((kapi2Tip==1)&&((kapiSivici==1)||(kapiSivici==3)))
				  {
					  HAL_GPIO_WritePin(kapi2Out_GPIO_Port, kapi2Out_Pin, GPIO_PIN_RESET);
				  }


				  //   kapi tabla kontrol


				  if((kapitablaTip==0)&&((kapiSivici==2)||(kapiSivici==3))&&(HAL_GPIO_ReadPin(tablakapisiviciIn_GPIO_Port, tablakapisiviciIn_Pin)==1)&&(butonKontrol==0))
				  {

					  HAL_GPIO_WritePin(tablaKapiOut_GPIO_Port, tablaKapiOut_Pin, GPIO_PIN_SET);
					  timer = millis;
					  bekle();
				  }

				  if((millis-timer >= kapiTablaAcSure))
				  {
					  HAL_GPIO_WritePin(tablaKapiOut_GPIO_Port, tablaKapiOut_Pin, GPIO_PIN_RESET);
				  }

				  if((kapitablaTip==1)&&((kapiSivici==2)||(kapiSivici==3))&&(HAL_GPIO_ReadPin(tablakapisiviciIn_GPIO_Port, tablakapisiviciIn_Pin)==1))
				  {
					  HAL_GPIO_WritePin(tablaKapiOut_GPIO_Port, tablaKapiOut_Pin, GPIO_PIN_SET);
				  }

				  else if((kapitablaTip==1)&&((kapiSivici==2)||(kapiSivici==3)))
				  {
					  HAL_GPIO_WritePin(tablaKapiOut_GPIO_Port, tablaKapiOut_Pin, GPIO_PIN_RESET);
				  }

				  //Max calisma suresi asildi.

				  if((motorcalisiyor)||(asagivalfcalisiyor)||(devmotorasagicalisiyor)){


					  if(millis-makinecalistmr1>=makineCalismaTmr)
					  {
						  hataVar=1;
						  lcd_print(1, 1, "calisma hatasi");
					  }

				  }
				  else if((HAL_GPIO_ReadPin(yukaristartIn_GPIO_Port, yukaristartIn_Pin)==0)
						  && (HAL_GPIO_ReadPin(asagiStartIn_GPIO_Port, asagiStartIn_Pin)==0)
						  && (HAL_GPIO_ReadPin(devirmeasagigeriIn_GPIO_Port, devirmeasagigeriIn_Pin)==0)
						  && (HAL_GPIO_ReadPin(devirmeyukariileriIn_GPIO_Port, devirmeyukariileriIn_Pin)==0)
						  && (HAL_GPIO_ReadPin(enterbutonIn_GPIO_Port, enterbutonIn_Pin)==1)&&(hataVar==1)){

					  hataVar=0;
					  lcd_print(1, 1, "   Ana Sayfa   ");
				  }

				  if((yukarimotorcalisiyor==0)
						  && (asagivalfcalisiyor==0)
						  && (devmotoryukaricalisiyor==0)
						  && (devmotorasagicalisiyor==0)){

					  	  makineCalisiyor=0;
					  	  makinecalistmr1=millis;
						  }
				  else
					 makineCalisiyor=1;
				  } // aktif calisma son parantez.

				  // DEMO MOD BASLIYOR


				  // DEMO YUKARI CALISMA

				  if((demoMode==1)&&(stopVar)){

					  if((HAL_GPIO_ReadPin(ustlimitIn_GPIO_Port, ustlimitIn_Pin)==1)
						      && (demoAsagiCalis==0)
							  && (demoDevYukari==0)
							  && (demoDevAsagi==0)){
						  HAL_GPIO_WritePin(yukariValfOut_GPIO_Port, yukariValfOut_Pin, GPIO_PIN_SET);
						  demoYukariCalis=1;
					  }
					  else if(HAL_GPIO_ReadPin(ustlimitIn_GPIO_Port, ustlimitIn_Pin)==0){
						  HAL_GPIO_WritePin(yukariValfOut_GPIO_Port, yukariValfOut_Pin, GPIO_PIN_RESET);
						  demoYukariCalis=0;
					  }

					  // DEMO MOTOR CALISMASI

					  if((demoYukariCalis)||(demoDevYukari)||(demoDevAsagi)||(demoAsagiCalis)){

						  HAL_GPIO_WritePin(motorOut_GPIO_Port, motorOut_Pin, GPIO_PIN_SET);
						  HAL_GPIO_WritePin(motorIkinciHizOut_GPIO_Port, motorIkinciHizOut_Pin, GPIO_PIN_SET);

					  }
					  else {

						  HAL_GPIO_WritePin(motorOut_GPIO_Port, motorOut_Pin, GPIO_PIN_RESET);
						  HAL_GPIO_WritePin(motorIkinciHizOut_GPIO_Port, motorIkinciHizOut_Pin, GPIO_PIN_RESET);
					  }
					  if((HAL_GPIO_ReadPin(ustlimitIn_GPIO_Port, ustlimitIn_Pin)==0)
							  && (HAL_GPIO_ReadPin(devirmeYukariLimitIn_GPIO_Port, devirmeYukariLimitIn_Pin))
							  && (demoYukariCalis==0)
							  && (demoAsagiCalis==0)){


					  }

					  //DEVİRME YUKARI CALIS
					  if((HAL_GPIO_ReadPin(ustlimitIn_GPIO_Port, ustlimitIn_Pin)==0)
							  &&(HAL_GPIO_ReadPin(devirmeYukariLimitIn_GPIO_Port, devirmeYukariLimitIn_Pin)==1)
							  &&(demoYukariCalis==0)
							  &&(demoAsagiCalis==0)
							  && (demoDevAsagi==0)){
						  HAL_GPIO_WritePin(devirmeYukariIleriOut_GPIO_Port, devirmeYukariIleriOut_Pin, GPIO_PIN_SET);
						  demoDevYukari=1;
					  }
					  else{
						  HAL_GPIO_WritePin(devirmeYukariIleriOut_GPIO_Port, devirmeYukariIleriOut_Pin, GPIO_PIN_RESET);
						  demoDevYukari=0;
					  }

					  // DEVIRME ASAGI CALIS

					  if((HAL_GPIO_ReadPin(ustlimitIn_GPIO_Port, ustlimitIn_Pin)==0)
							  &&(HAL_GPIO_ReadPin(devirmeAsagiLimitIn_GPIO_Port, devirmeAsagiLimitIn_Pin)==1)
							  &&(demoYukariCalis==0)
							  &&(demoDevYukari==0)
							  && (demoAsagiCalis==0)){
						  HAL_GPIO_WritePin(devirmeAsagiGeriOut_GPIO_Port, devirmeAsagiGeriOut_Pin, GPIO_PIN_SET);
						  demoDevAsagi=1;
					  }
					  else{
						  HAL_GPIO_WritePin(devirmeAsagiGeriOut_GPIO_Port, devirmeAsagiGeriOut_Pin, GPIO_PIN_RESET);
						  demoDevAsagi=0;
					  }

					  // DEMO ASAGI CALISMA

					  if((HAL_GPIO_ReadPin(altlimitIn_GPIO_Port, altlimitIn_Pin)==1)
						      && (demoYukariCalis==0)
							  && (demoDevAsagi==0)
							  && (demoDevYukari==0)){
						  HAL_GPIO_WritePin(asagiValfOut_GPIO_Port, asagiValfOut_Pin, GPIO_PIN_SET);
						  HAL_GPIO_WritePin(yavaslamaValfOut_GPIO_Port, yavaslamaValfOut_Pin, GPIO_PIN_SET);
						  demoAsagiCalis=1;
						  demoCalismaSayisiYar=1;
					  }
					  else if ((HAL_GPIO_ReadPin(altlimitIn_GPIO_Port, altlimitIn_Pin)==0)){
						  HAL_GPIO_WritePin(asagiValfOut_GPIO_Port, asagiValfOut_Pin, GPIO_PIN_RESET);
						  HAL_GPIO_WritePin(yavaslamaValfOut_GPIO_Port, yavaslamaValfOut_Pin, GPIO_PIN_RESET);
						  demoAsagiCalis=0;
					  }

					  if(HAL_GPIO_ReadPin(altlimitIn_GPIO_Port, altlimitIn_Pin)==0)
					  {

						  HAL_GPIO_WritePin(kapi1Out_GPIO_Port, kapi1Out_Pin, GPIO_PIN_SET);
						  HAL_GPIO_WritePin(tablaKapiOut_GPIO_Port, tablaKapiOut_Pin, GPIO_PIN_SET);
						  timer3 = millis;

					  }

					  if(millis-timer3 >= 5)
					  {
						  HAL_GPIO_WritePin(kapi1Out_GPIO_Port, kapi1Out_Pin, GPIO_PIN_RESET);
						  HAL_GPIO_WritePin(tablaKapiOut_GPIO_Port, tablaKapiOut_Pin, GPIO_PIN_RESET);
					  }

					  if(HAL_GPIO_ReadPin(ustlimitIn_GPIO_Port, ustlimitIn_Pin)==0)
					  {

						  HAL_GPIO_WritePin(kapi2Out_GPIO_Port, kapi2Out_Pin, GPIO_PIN_SET);
						  timer3 = millis;

					  }

					  if(millis-timer3 >= 5)
					  {
						  HAL_GPIO_WritePin(kapi2Out_GPIO_Port, kapi2Out_Pin, GPIO_PIN_RESET);

					  }
					  if((demoYukariCalis==1) && (demoCalismaSayisiYar==1)){
						  //mesajYazildi=0;
							calismaSayisi1=calismaSayisi1+1;
							if(calismaSayisi1>9){
								calismaSayisi1=0;
								calismaSayisi10=calismaSayisi10+1;
							}
							if(calismaSayisi10>9){
								calismaSayisi10=0;
								calismaSayisi100=calismaSayisi100+1;
							}
							if(calismaSayisi100>9){
								calismaSayisi100=0;
								calismaSayisi1000=calismaSayisi1000+1;
							}
							if(calismaSayisi1000>9){
								calismaSayisi1000=0;
								calismaSayisi10000=calismaSayisi10000+1;
							}
							eepromData[32]=calismaSayisi10000;
							eepromData[31]=calismaSayisi1000;
							eepromData[30]=calismaSayisi100;
							eepromData[29]=calismaSayisi10;
							eepromData[28]=calismaSayisi1;
							hafizaYaz=1;
		   				  //mesajYazildi=0;
						  demoCalismaSayisiYar=0;
					  }
					  if (menuGiris==0){
						  lcd_print(1,1," Calisma Sayisi ");
						    itoa(calismaSayisi10000, snum, 10);
						    lcd_print(2,12,snum);
						    itoa(calismaSayisi1000, snum, 10);
						    lcd_print(2,13,snum);
						    itoa(calismaSayisi100, snum, 10);
						    lcd_print(2,14,snum);
						    itoa(calismaSayisi10, snum, 10);
						    lcd_print(2,15,snum);
						    itoa(calismaSayisi1, snum, 10);
						    lcd_print(2,16,snum);
						  mesajYazildi=1;
					  }
				  }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief CAN Initialization Function
  * @param None
  * @retval None
  */
static void MX_CAN_Init(void)
{

  /* USER CODE BEGIN CAN_Init 0 */
  /* USER CODE END CAN_Init 0 */

  /* USER CODE BEGIN CAN_Init 1 */
  /* USER CODE END CAN_Init 1 */
  hcan.Instance = CAN1;
  hcan.Init.Prescaler = 16;
  hcan.Init.Mode = CAN_MODE_NORMAL;
  hcan.Init.SyncJumpWidth = CAN_SJW_1TQ;
  hcan.Init.TimeSeg1 = CAN_BS1_1TQ;
  hcan.Init.TimeSeg2 = CAN_BS2_1TQ;
  hcan.Init.TimeTriggeredMode = DISABLE;
  hcan.Init.AutoBusOff = DISABLE;
  hcan.Init.AutoWakeUp = DISABLE;
  hcan.Init.AutoRetransmission = DISABLE;
  hcan.Init.ReceiveFifoLocked = DISABLE;
  hcan.Init.TransmitFifoPriority = DISABLE;
  if (HAL_CAN_Init(&hcan) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN CAN_Init 2 */
  /* USER CODE END CAN_Init 2 */

}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */
  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */
  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 400000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */
  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief TIM1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM1_Init(void)
{

  /* USER CODE BEGIN TIM1_Init 0 */

  /* USER CODE END TIM1_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM1_Init 1 */

  /* USER CODE END TIM1_Init 1 */
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 35999;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 1999;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM1_Init 2 */

  /* USER CODE END TIM1_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, buzzerOut_Pin|tablaKapiOut_Pin|kapi2Out_Pin|kapi1Out_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, devirmeAsagiGeriOut_Pin|devirmeYukariIleriOut_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, yavaslamaValfOut_Pin|asagiValfOut_Pin|yukariValfOut_Pin|motorIkinciHizOut_Pin
                          |motorOut_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : yukariYavaslamaLimitIn_Pin yavaslamaLimitIn_Pin basincSalteriIn_Pin ecercevesiIn_Pin
                           ustlimitIn_Pin altlimitIn_Pin geributonIn_Pin devirmeasagigeriIn_Pin
                           kapiacIn_Pin ustkapiacIn_Pin tablakapiacIn_Pin devirmeYukariLimitIn_Pin
                           devirmeAsagiLimitIn_Pin */
  GPIO_InitStruct.Pin = yukariYavaslamaLimitIn_Pin|yavaslamaLimitIn_Pin|basincSalteriIn_Pin|ecercevesiIn_Pin
                          |ustlimitIn_Pin|altlimitIn_Pin|geributonIn_Pin|devirmeasagigeriIn_Pin
                          |kapiacIn_Pin|ustkapiacIn_Pin|tablakapiacIn_Pin|devirmeYukariLimitIn_Pin
                          |devirmeAsagiLimitIn_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : ileributonIn_Pin yukaributonIn_Pin asagibutonIn_Pin enterbutonIn_Pin
                           tablakapisiviciIn_Pin kapiSiviciIn_Pin */
  GPIO_InitStruct.Pin = ileributonIn_Pin|yukaributonIn_Pin|asagibutonIn_Pin|enterbutonIn_Pin
                          |tablakapisiviciIn_Pin|kapiSiviciIn_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : buzzerOut_Pin tablaKapiOut_Pin kapi2Out_Pin kapi1Out_Pin */
  GPIO_InitStruct.Pin = buzzerOut_Pin|tablaKapiOut_Pin|kapi2Out_Pin|kapi1Out_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : devirmeAsagiGeriOut_Pin devirmeYukariIleriOut_Pin */
  GPIO_InitStruct.Pin = devirmeAsagiGeriOut_Pin|devirmeYukariIleriOut_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : yavaslamaValfOut_Pin asagiValfOut_Pin yukariValfOut_Pin motorIkinciHizOut_Pin
                           motorOut_Pin */
  GPIO_InitStruct.Pin = yavaslamaValfOut_Pin|asagiValfOut_Pin|yukariValfOut_Pin|motorIkinciHizOut_Pin
                          |motorOut_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : acilstopIn_Pin yukaristartIn_Pin asagiStartIn_Pin devirmeyukariileriIn_Pin */
  GPIO_InitStruct.Pin = acilstopIn_Pin|yukaristartIn_Pin|asagiStartIn_Pin|devirmeyukariileriIn_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
/* USER CODE END 4 */

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const * argument)
{
  /* USER CODE BEGIN 5 */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END 5 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
