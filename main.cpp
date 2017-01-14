#include <cstdlib>
#include <iostream>
#include <allegro.h>
#include <alpng.h>
#include <cmath>

#define siyah makecol(0,0,0)
#define yaziRenk makecol(0,140,0)

BITMAP *temelBuffer, *ustBuffer;

using namespace std;

////////////////////////////////////////////////////////////////////////////////
class motor{
    int hiz, motorDurum, devirAci, hararetDurum, basincDurum, yagDurum, hararetAci, yakitAci, IsitmaDiognastikDenge[3][1];
  
protected:
    BITMAP *gazBasincGosterge, *kilometreGosterge, *yakitGosterge, *hararetGosterge, *yagAktif, *yag;
    BITMAP *onIsitmaAktif, *onIsitma, *diognastikAktif, *diognastik, *dinamikDengeAktif, *dinamikDenge;
    int hizAci, motorBasinc,yakitDurum ;    
public:
    
    motor(){
        hiz=0, hararetDurum=0, hizAci=0, devirAci=0, basincDurum=0, yakitDurum=160, yagDurum=50, hararetAci=0, yakitAci=0;
        IsitmaDiognastikDenge[0][0]=0, IsitmaDiognastikDenge[1][0]=0,IsitmaDiognastikDenge[2][0]=0;
        //motorBasinc=93;
        gazBasincGosterge=load_bmp("img/icon/buyukImlec.bmp", NULL);
        kilometreGosterge=load_bmp("img/icon/buyukImlec.bmp", NULL);
        yakitGosterge=load_bmp("img/icon/kucukImlec.bmp", NULL);
        hararetGosterge=load_bmp("img/icon/kucukImlec.bmp", NULL);
        yagAktif=load_bmp("img/icon/motorYagBasincAktif.bmp", NULL);
        yag=load_bmp("img/icon/pasif/motorYagBasinc.bmp", NULL);
        onIsitmaAktif=load_bmp("img/icon/motorOnIsitmaAktif.bmp", NULL);
        onIsitma=load_bmp("img/icon/pasif/motorOnIsitma.bmp", NULL);
        diognastikAktif=load_bmp("img/icon/motorDiognastikAktif.bmp", NULL);
        diognastik=load_bmp("img/icon/pasif/motorDiognastik.bmp", NULL);
        dinamikDengeAktif=load_bmp("img/icon/dinamikDengeKontrolAktif.bmp", NULL);
        dinamikDenge=load_bmp("img/icon/pasif/dinamikDengeKontrol.bmp", NULL);
    }//MOTOR
    
    
    void ikazIsitmaDiognastikDenge(){
         
         if(IsitmaDiognastikDenge[0][0]==0){
                                  draw_sprite(temelBuffer, onIsitma, 270, 71); }         
         if(IsitmaDiognastikDenge[0][0]==1){ 
                                  draw_sprite(temelBuffer, onIsitmaAktif, 270, 71); }         
         if(IsitmaDiognastikDenge[1][0]==0){ 
                                  draw_sprite(temelBuffer, diognastik, 909, 71); }         
         if(IsitmaDiognastikDenge[1][0]==1){ 
                                  draw_sprite(temelBuffer, diognastikAktif, 909, 71); }        
         if(IsitmaDiognastikDenge[2][0]==0){ 
                                  draw_sprite(temelBuffer, dinamikDenge, 22, 286); } 
         if(IsitmaDiognastikDenge[2][0]==1){ 
                                  draw_sprite(temelBuffer, dinamikDengeAktif, 22, 286); } 
                 
         
         }
         
    int getIsitmaDiognastikDenge(int indis){
         
        return IsitmaDiognastikDenge[indis][0];
    }//getSinyalDurum
    
    void setIsitmaDiognastikDenge(int indis){
         
         if(IsitmaDiognastikDenge[indis][0]==0){
                                    if(indis==0 || indis==1){
                                                    IsitmaDiognastikDenge[indis][0]=1;
                                                    //IsitmaDiognastikDenge[!indis][0]=0;         
                                                }else{
                                                      IsitmaDiognastikDenge[indis][0]=1;
                                                }
                                     
         }else{
               IsitmaDiognastikDenge[indis][0]=0;
         }
    }//setFarDurum
    
    
    
    
    
    
    
    
    int getBasinc(){
        return motorBasinc;
    }
    
    void setBasinc(int basincD, int basincDeger){
         
         //if(basincDurum==0){
           //                 }
         motorBasinc=basincDeger*basincD;
         basincDurum=basincD;
         
         
          //akuSarjAzalt(basincDeger);
          yakitAzalt(motorBasinc);
          yagAzalt(motorBasinc);
                
    }
  
    
    void motorDevirGoster(){
        
         devirAci = basincDurum*motorBasinc;
     
               pivot_sprite( temelBuffer, gazBasincGosterge, 437, 252, 0, 0, itofix(93+devirAci));
     
         
        
    }//motorDevirGosterge
         
       
    
    
    void hizGoster(){
         
         
        hizAci=motorBasinc;
        //hizAci2=hizAci;
        if(hizAci<=300){
           hizAci=(motorBasinc*0.3);
        pivot_sprite( temelBuffer, kilometreGosterge, 787, 251, 0, 0, itofix(93+hizAci));         
        
        
        }else{
              hizAci=0;
              //pivot_sprite( temelBuffer, kilometreGosterge, 787, 251, 0, 0, itofix(93+hizAci)); 
              }
      
       
         };//HIZ GOSTER
  
 
     void hararetGoster(){
          hararetAci=motorBasinc;
 
          if(hararetAci<=300){
           hararetAci=(motorBasinc*0.15);
        pivot_sprite( temelBuffer, hararetGosterge, 1080, 334, 0, 0, itofix(93+hararetAci));         
        
        
        }else{
              hararetAci=0;
              //pivot_sprite( temelBuffer, kilometreGosterge, 787, 251, 0, 0, itofix(93+hizAci)); 
              }
 
          };
     
     
     void yakitAzalt(int motorBasinc){                  
                  yakitDurum=yakitDurum-(motorBasinc*0.0008);                                
                  }
     
      
     void yakitGoster(){
            
 
          //if(yakitAci<=300){
        if(yakitDurum<=96){
                            
                           pivot_sprite( temelBuffer, yakitGosterge, 249, 334, 0, 0, itofix(yakitDurum));    
                           yakitDurum=96;
                           }else{
                                 
           //yakitDurum=(yakitDurum*0.01);
        pivot_sprite( temelBuffer, yakitGosterge, 249, 334, 0, 0, itofix(yakitDurum));         
        }
  
    };
          
     int getYakitDurum(){
         return yakitDurum;
         }   
    
    
    ///////////////////////////////////////          
          
      void yagAzalt(int motorBasinc){                  
                  yagDurum=yagDurum-(motorBasinc*0.01);                                
                  }
          
     void yagBildir(){
          
          
          if(yagDurum<20){
                            
                          
                           draw_sprite(temelBuffer, yagAktif, 1071, 158);    
                           //yakitDurum=96;
                           yagDurum=19;
                           }else{
                                 draw_sprite(temelBuffer, yag, 1071, 158);    
                                            //yakitDurum=(yakitDurum*0.01);
                
        }
          
          };
   
};//MOTOR SINIF

////////////////////////////////////////////////////////////////////////////////
class kilometre : public motor{
    int kilometreSay, gunlukKilometre;
    
public:
    kilometre(){
        kilometreSay=0; gunlukKilometre=0;
        
        
    }
    
    void kilometreSayac(){
         kilometreSay+=hizAci;
         };
         
    void kilometreGunlukSayac(){
         gunlukKilometre+=hizAci;
         
          textprintf(temelBuffer, font, 545, 55, yaziRenk, "%-3d",gunlukKilometre);
         };
          
    //void gunlukKilometreSifirla();
    
    int getGunlukKilometre(){
        return gunlukKilometre;
        }
    
};
////////////////////////////////////////////////////////////////////////////////

class aku{
    int akuSarj;
    BITMAP *akuSarjAktif, *akuSarjPasif;
public:
    aku(){
         akuSarj=100;
         
         akuSarjAktif=load_bmp("img/icon/akuSarjAktif.bmp", NULL);
         akuSarjPasif=load_bmp("img/icon/pasif/akuSarj.bmp", NULL);
         };
    
    
    
    void akuSarjAzalt(int otoDrm,int motorBasinc){
                  
                  akuSarj=akuSarj-((motorBasinc*otoDrm)*0.1);
                                
                  }
                  
    void akuSarjIkaz(){
         if(akuSarj<20){
                  draw_sprite(temelBuffer, akuSarjAktif, 1020, 157);
                  //textprintf(temelBuffer, font, 545, 55, yaziRenk, "%-3d",akuSarj);
                    }else{
                      draw_sprite(temelBuffer, akuSarjPasif, 1020, 157);
                    //  textprintf(temelBuffer, font, 545, 55, yaziRenk, "%-3d",akuSarj);
                          }
         }
};
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
class far{
   
    BITMAP *sagSinyal, *solSinyal;
    BITMAP *sagSinyalAktif, *solSinyalAktif;
    
    BITMAP *uzunHuzme, *kisaHuzme, *onSis, *arkaSis;
    BITMAP *uzunHuzmeAktif, *kisaHuzmeAktif, *onSisAktif, *arkaSisAktif;
    
    int sinyalDurum[2][1];
    int farDurum[4][1];
    
    
    
public:
    far(){
         sinyalDurum[0][0]=0, sinyalDurum[1][0]=0; 
         farDurum[0][0]=0, farDurum[1][0]=0, farDurum[2][0]=0, farDurum[3][0]=0; 
         
         
          
         solSinyal = load_bmp("img/icon/pasif/solSinyal.bmp", NULL);
         sagSinyal = load_bmp("img/icon/pasif/sagSinyal.bmp", NULL); 
         uzunHuzme = load_bmp("img/icon/pasif/uzunFar.bmp", NULL); 
         kisaHuzme = load_bmp("img/icon/pasif/kisaFar.bmp", NULL); 
         onSis = load_bmp("img/icon/pasif/onSisFar.bmp", NULL); 
         arkaSis = load_bmp("img/icon/pasif/arkaSisFar.bmp", NULL); 
    
         solSinyalAktif = load_bmp("img/icon/solSinyalAktif.bmp", NULL);
         sagSinyalAktif = load_bmp("img/icon/sagSinyalAktif.bmp", NULL); 
         uzunHuzmeAktif = load_bmp("img/icon/uzunFarAktif.bmp", NULL); 
         kisaHuzmeAktif = load_bmp("img/icon/kisaFarAktif.bmp", NULL); 
         onSisAktif = load_bmp("img/icon/onSisFarAktif.bmp", NULL); 
         arkaSisAktif = load_bmp("img/icon/arkaSisFarAktif.bmp", NULL); 
    }   
       
    void sinyal(){
         
         if(sinyalDurum[0][0]==0){
                                  draw_sprite(temelBuffer, solSinyal, 472, 47); }         
         if(sinyalDurum[0][0]==1){ 
                                  draw_sprite(temelBuffer, solSinyalAktif, 472, 47);
                                   }         
         if(sinyalDurum[1][0]==0){
                                  draw_sprite(temelBuffer, sagSinyal, 705, 47);}               
         if(sinyalDurum[1][0]==1){
                                  draw_sprite(temelBuffer, sagSinyalAktif, 705, 47);}
       
    }//sinyal
         
    
    int getSinyalDurum(int indis){
         
        return sinyalDurum[indis][0];
    }//getSinyalDurum
    
    void setSinyalDurum(int indis){
         
         if(sinyalDurum[indis][0]==0){
                                     sinyalDurum[indis][0]=1;
                                     sinyalDurum[!indis][0]=0;
                                     }else{
                                     sinyalDurum[indis][0]=0;
                                     }
    }//setSinyalDurum
    
    
    /////////////////////////////////////////////
    ////                                     ////
    ////                                     ////
    /////////////////////////////////////////////     
    void ikazFar(){
         
         if(farDurum[0][0]==0){
                                  draw_sprite(temelBuffer, uzunHuzme, 952, 110); }         
         if(farDurum[0][0]==1){ 
                                  draw_sprite(temelBuffer, uzunHuzmeAktif, 952, 110); }         
         if(farDurum[1][0]==0){ 
                                  draw_sprite(temelBuffer, kisaHuzme, 1012, 110); }         
         if(farDurum[1][0]==1){ 
                                  draw_sprite(temelBuffer, kisaHuzmeAktif, 1012, 110); }        
         if(farDurum[2][0]==0){ 
                                  draw_sprite(temelBuffer, onSis, 179, 110); } 
         if(farDurum[2][0]==1){ 
                                  draw_sprite(temelBuffer, onSisAktif, 179, 110); } 
         if(farDurum[3][0]==0){ 
                                  draw_sprite(temelBuffer, arkaSis, 232, 110); } 
         if(farDurum[3][0]==1){ 
                                  draw_sprite(temelBuffer, arkaSisAktif, 232, 110); }         
         
         }
         
    int getFarDurum(int indis){
         
        return farDurum[indis][0];
    }//getSinyalDurum
    
    void setFarDurum(int indis){
         
         if(farDurum[indis][0]==0){
                                    if(indis==0 || indis==1){
                                                    farDurum[indis][0]=1;
                                                    farDurum[!indis][0]=0;         
                                                }else{
                                                      farDurum[indis][0]=1;
                                                }
                                     
         }else{
               farDurum[indis][0]=0;
         }
    }//setFarDurum
    
    
    
   
    
};

////////////////////////////////////////////////////////////////////////////////
class fren{
    int frenDurum[2][1];
    BITMAP *abs, *absAktif, *elFren, *elFrenAktif;
public:
   fren(){
          frenDurum[0][0]=0, frenDurum[1][0]=1;
          
          abs=load_bmp("img/icon/pasif/abs.bmp", NULL);
          absAktif=load_bmp("img/icon/absAktif.bmp", NULL);
          elFren=load_bmp("img/icon/pasif/elFreni.bmp", NULL);
          elFrenAktif=load_bmp("img/icon/elFreniAktif.bmp", NULL);
          
          }
    
    
    void ikazFren(){
          if(frenDurum[0][0]==0){
                                  draw_sprite(temelBuffer, abs, 199, 157); }         
         if(frenDurum[0][0]==1){ 
                                  draw_sprite(temelBuffer, absAktif, 199, 157); }         
         if(frenDurum[1][0]==0){
                                  draw_sprite(temelBuffer, elFren, 968, 157);}               
         if(frenDurum[1][0]==1){
                                  draw_sprite(temelBuffer, elFrenAktif, 968, 157);}
       
         }
    
    int getFrenDurum(int indis){
        return frenDurum[indis][0];
        }
        
    void setFrenDurum(int indis){
         if(frenDurum[indis][0]==0){
                                     frenDurum[indis][0]=1;
                                     frenDurum[!indis][0]=0;
                                     }else{
                                     frenDurum[indis][0]=0;
                                     }
         }
    
    
};



class ARABA : public aku, public far, public fren, public kilometre{
    string marka, model;
    int kemerDurum, airbagDurum[2][1];
    BITMAP *genelPanel, *kemerAktif, *kemer, *airbagAktif, *airbag, *yolcuAirbagAktif, *yolcuAirbag, *stopAktif, *stop;
   public:
          ARABA(string mrk, string mdl){                            
                  
                  kemerDurum=1, airbagDurum[0][0]=0, airbagDurum[1][0]=0;
                  
                  marka=mrk;
                  model=mdl;
                  
                  
                  kemerAktif = load_bmp("img/icon/kemerAktif.bmp", NULL);
                  kemer=load_bmp("img/icon/pasif/kemer.bmp", NULL);

                  airbagAktif=load_bmp("img/icon/havaYastigiAktif.bmp", NULL);
                  airbag=load_bmp("img/icon/pasif/havaYastigi.bmp", NULL);
                  yolcuAirbagAktif=load_bmp("img/icon/yolcuHavaYastikAktif.bmp", NULL);
                  yolcuAirbag=load_bmp("img/icon/pasif/yolcuHavaYastik.bmp", NULL);
                  
                  stopAktif=load_bmp("img/icon/stopAktif.bmp", NULL);
                  stop=load_bmp("img/icon/pasif/stop.bmp", NULL);
                  
                  
                  genelPanel= load_tga("img/panelGenel.tga",NULL);
                  draw_trans_sprite(temelBuffer, genelPanel, 0, 0); //this is important  
                  
                  
                  
                  //motor::imlecOlustur();
                  }
                  
        //AIRBAG//////////////////////////////////////////////////
          
           
    void airbagIkaz(){
         
         if(airbagDurum[0][0]==0){
                                  draw_sprite(temelBuffer, airbag, 150, 157); }         
         if(airbagDurum[0][0]==1){ 
                                  draw_sprite(temelBuffer, airbagAktif, 150, 157); }         
         if(airbagDurum[1][0]==0){
                                  draw_sprite(temelBuffer, yolcuAirbag, 99, 156);}               
         if(airbagDurum[1][0]==1){
                                  draw_sprite(temelBuffer, yolcuAirbagAktif, 99, 156);}
       
    }//sinyal
         
    
    int getAirbagDurum(int indis){
         
        return airbagDurum[indis][0];
    }//getSinyalDurum
    
    void setAirbagDurum(int indis){
         
         if(airbagDurum[indis][0]==0){
                                     airbagDurum[indis][0]=1;
                                  //   airbagDurum[!indis][0]=0;
                                     }else{
                                     airbagDurum[indis][0]=0;
                                     }
    }//setSinyalDurum
    
        
        
        //////////////////////////////////////////////////AIRBAG//
       
       
       
         //KEMER////////////////////////////////////////////////// 
          
        int getKemerDurum(){         
            return kemerDurum;
         }//getKemerDurum
    
         void setKemerDurum(){
              if(kemerDurum==0){
                                kemerDurum=1;
                                }else{
                                       kemerDurum=0;
                                       } 
         }//setKemerDurum
         
         
          
        void ikazKemer(){
               if(kemerDurum==0){
                  draw_sprite(temelBuffer, kemer, 55, 206);          
                               }else if(kemerDurum==1){
                                 draw_sprite(temelBuffer, kemerAktif, 55, 206);    
                                     }
               }
               
               
        //////////////////////////////////////////////////KEMER//
         
         
                  
          void yenile(){
               //clear(temelBuffer);
               clear_to_color(temelBuffer, makecol(51, 51, 51));
               draw_trans_sprite(temelBuffer, genelPanel, 0, 0); 
              
               //blit(temelBuffer,ustBuffer,0,0,0,0,SCREEN_W,SCREEN_H);
              // hizGoster();
              
              if(getYakitDurum()<=96){
                       draw_sprite(temelBuffer, stop, 748, 354);
                                   //setBasinc(0,0);
                                   //setYakitDurum(96);
                                   yakitAzalt(0);
                                   //yakitDurum=160;
                                   yagAzalt(0);
                                   akuSarjAzalt(0,0);
                                   motorDevirGoster();
                                   hizGoster();
                                   hararetGoster();
                                   yakitGoster();                
                                      
              
              }else if(getFrenDurum(0)==1 || getFrenDurum(1)==1 || getKemerDurum()==1){
                    
                                   sinyal();
                                   ikazFar();
                                   ikazKemer();
                                   airbagIkaz();
                                   ikazFren();
                                   ikazIsitmaDiognastikDenge();
                                   draw_sprite(temelBuffer, stopAktif, 748, 354);
                                   //setBasinc(0,0);
                                   //setYakitDurum(96);
                                   yakitAzalt(0);
                                   //yakitDurum=160;
                                   yagAzalt(0);
                                   akuSarjAzalt(0,0);
                                   motorDevirGoster();
                                   hizGoster();
                                   hararetGoster();
                                   yakitGoster();    
                                      }else{
               sinyal();
               ikazFar();
               ikazKemer();
               airbagIkaz();
               ikazFren();
               ikazIsitmaDiognastikDenge();             
                                            
               draw_sprite(temelBuffer, stop, 748, 354);
               motorDevirGoster();
               hizGoster();
               hararetGoster();
               yakitGoster();
               yagBildir();
               kilometreSayac();
               kilometreGunlukSayac();
               akuSarjIkaz();
               }
              // blit(ustBuffer,temelBuffer,0,0,0,0,SCREEN_W,SCREEN_H); 
              blit(temelBuffer,screen,0,0,0,0,SCREEN_W,SCREEN_H); 
               };
        
}; 

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


int main() {  
    
int cikis=0, basincSayac=0, restDeger=300, otoDurum=1;

    


allegro_init();
install_keyboard();

set_color_depth(desktop_color_depth());
set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1200, 500, 0, 0);


temelBuffer = create_bitmap(SCREEN_W, SCREEN_H);
ustBuffer = create_bitmap(SCREEN_W, SCREEN_H);

clear_to_color(temelBuffer, makecol(51, 51, 51));

set_alpha_blender();
ARABA araba("peugeot","206");

while(cikis!=1){
        
araba.yenile();       

        
        if(key[KEY_LEFT]){
              araba.setSinyalDurum(0);             
              rest(restDeger);
        }else if(key[KEY_RIGHT]){
              araba.setSinyalDurum(1);              
              rest(restDeger);
        }else if(key[KEY_U]){
              araba.setFarDurum(0);
              rest(restDeger);
        }else if(key[KEY_K]){
              araba.setFarDurum(1);
              rest(restDeger);
        }else if(key[KEY_O]){
              araba.setFarDurum(2);
              rest(restDeger);
        }else if(key[KEY_I]){
              araba.setFarDurum(3);
              rest(restDeger);
        }else if(key[KEY_Z]){
              araba.setKemerDurum();
              rest(restDeger);
        }else if(key[KEY_X]){
               araba.setAirbagDurum(0);
               rest(restDeger);                         
         }else if(key[KEY_C]){
               araba.setAirbagDurum(1);
               rest(restDeger);               
         }else if(key[KEY_G]){
               araba.setFrenDurum(0);
               rest(restDeger);
         }else if(key[KEY_F]){
               araba.setFrenDurum(1);
               rest(restDeger);
         }else if(key[KEY_W]){
                
                 if(araba.getYakitDurum()<=96 || araba.getFrenDurum(0)==1 || araba.getFrenDurum(1)==1 || araba.getKemerDurum()==1){
                                      otoDurum=0;  
                                        }else{
                                               otoDurum=1;
                                              }
                
                if(basincSayac>=196){
                                    //basincSayac=196;
                                    basincSayac=basincSayac-28;
                                    araba.setBasinc(otoDurum,basincSayac);
                                    araba.akuSarjAzalt(otoDurum,basincSayac);
                                    }else if(basincSayac<196){
                                          basincSayac=basincSayac+28;                                         
                                          
                                          araba.setBasinc(otoDurum,basincSayac);
                                          araba.akuSarjAzalt(otoDurum,basincSayac);
                                          }
                                          
                
              
                //basincSayac=11.25*(basincSayac/8);
                //basincSayac=(PI/180)*basincSayac;
                
                
                
                rest(60);
         }else if(key[KEY_S]){
                
                if(basincSayac==0){
                          basincSayac=0;
                          araba.setBasinc(otoDurum,basincSayac);
                          //araba.akuSarjAzalt(basincSayac);
                          }else{
                                basincSayac=basincSayac-28;
                                araba.setBasinc(otoDurum,basincSayac);
                                araba.akuSarjAzalt(otoDurum,basincSayac);
                                }//if 0
                //basincSayac=11.25*(basincSayac/8);
                //basincSayac=(PI/180)*basincSayac;
                
                
                
                rest(60);
         }else if(key[KEY_V]){
               araba.setIsitmaDiognastikDenge(0);
              rest(restDeger);
         }else if(key[KEY_B]){
               araba.setIsitmaDiognastikDenge(1);
              rest(restDeger);
         }else if(key[KEY_N]){
               araba.setIsitmaDiognastikDenge(2);
              rest(restDeger);
         }
         
         else if(key[KEY_ESC]){
                    
                    cikis=1;
                 rest(restDeger);
         
         }else{
               
               if(araba.getYakitDurum()<=96 || araba.getFrenDurum(0)==1 || araba.getFrenDurum(1)==1 || araba.getKemerDurum()==1){
                                      otoDurum=0;  
                                        }else{
                                               otoDurum=1;
                                              }
               
                        //BASINC
                          if(basincSayac==0){
                          basincSayac=0;
                          araba.setBasinc(otoDurum,basincSayac);
                          //araba.akuSarjAzalt(basincSayac);
                          }else{
                                basincSayac=basincSayac-28;
                                araba.setBasinc(otoDurum,basincSayac);
                                araba.akuSarjAzalt(otoDurum,basincSayac);
                                }//if 0
                          
                           rest(60);
                          //SON BASINC
                           
                           
                          }//key

};

readkey();
return 0;
}
END_OF_MAIN()

