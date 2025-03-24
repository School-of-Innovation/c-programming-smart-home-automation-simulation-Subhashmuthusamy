/*
 * 🚨 WARNING: CHALLENGE MODE ACTIVATED 🚨
 * 
 * 1️⃣ Sit back, take a deep breath, and **THINK**.
 * 2️⃣ For the next **10 minutes**, avoid using **Gen AI, ChatGPT, or any shortcuts**.
 * 3️⃣ Trust your **brain**—you’re smarter than you think!
 * 4️⃣ Consider yourself a **LOSER** if you cheat. Seriously, promise yourself you won't. 😤
 * 5️⃣ If you solve it on your own, **you WIN** and level up as a true programmer and come and meet me ! 
 * 
 * 
 * 💡 Remember: The best coders aren’t the ones who copy-paste. They are the ones who **struggle, think, fail, and then succeed.** 
 *    
 * Now, write your code! You got this! 💪🔥
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 
 void initializeSystem(int rooms, int lights[], int locks[], int motion[], int temperature[]);
 void displayMenu();
 void toggleLight(int rooms, int lights[]);
 void readTemperature(int rooms, int temperature[]);
 void checkMotion(int rooms, int motion[]);
 void securitySystem(int rooms, int locks[]);
 void analyzeHouseStatus(int rooms, int lights[], int locks[], int motion[], int temperature[]);
 
 int main() {
     int rooms;
     
     printf("Enter number of rooms: ");
     scanf("%d", &rooms);
 
     if (rooms <= 0) {
         printf("Invalid number of rooms!\n");
         return 1;
     }
 
     int lights[rooms], locks[rooms], motion[rooms], temperature[rooms];
 
     srand(time(NULL));  // Seed random number generator
     initializeSystem(rooms, lights, locks, motion, temperature);
     
     int choice;
     
     do {
         displayMenu();
         printf("Enter your choice: ");
         scanf("%d", &choice);
         
         switch (choice) {
             case 1: toggleLight(rooms, lights); break;
             case 2: readTemperature(rooms, temperature); break;
             case 3: checkMotion(rooms, motion); break;
             case 4: securitySystem(rooms, locks); break;
             case 5: analyzeHouseStatus(rooms, lights, locks, motion, temperature); break;
             case 6: printf("Exiting...\n"); break;
             default: printf("Invalid choice! Try again.\n");
         }
 
     } while (choice != 6);
     
     return 0;
 }
 
 void initializeSystem(int rooms, int lights[], int locks[], int motion[], int temperature[]) {
     for (int i = 0; i < rooms; i++) {
         lights[i] = 0;        // Lights OFF
         locks[i] = 1;         // Doors LOCKED
         motion[i] = 0;        // No motion detected
         temperature[i] = 22 + (rand() % 10); // Random temperature between 22-31°C
     }
     printf("System initialized successfully.\n");
 }
 
 void displayMenu() {
     printf("\n===== Smart Home Menu =====\n");
     printf("1. Toggle Light\n");
     printf("2. Read Temperature\n");
     printf("3. Check Motion Sensor\n");
     printf("4. Lock/Unlock Security System\n");
     printf("5. House Status Summary\n");
     printf("6. Exit\n");
 }
 
 void toggleLight(int rooms, int lights[]) {
     int room;
     printf("Enter room number to toggle light (1-%d): ", rooms);
     scanf("%d", &room);
     
     if (room >= 1 && room <= rooms) {
         lights[room - 1] = !lights[room - 1];
         printf("Light in Room %d is now %s.\n", room, lights[room - 1] ? "ON" : "OFF");
     } else {
         printf("Invalid room number!\n");
     }
 }
 
 void readTemperature(int rooms, int temperature[]) {
     int room;
     printf("Enter room number (1-%d): ", rooms);
     scanf("%d", &room);
     
     if (room >= 1 && room <= rooms) {
         printf("Temperature in Room %d: %d°C\n", room, temperature[room - 1]);
     } else {
         printf("Invalid room number!\n");
     }
 }
 
 void checkMotion(int rooms, int motion[]) {
     int room;
     printf("Enter room number to check motion sensor (1-%d): ", rooms);
     scanf("%d", &room);
     
     if (room >= 1 && room <= rooms) {
         motion[room - 1] = !motion[room - 1];  // Toggle motion detection
         printf("Motion in Room %d is now %s.\n", room, motion[room - 1] ? "DETECTED" : "NOT DETECTED");
     } else {
         printf("Invalid room number!\n");
     }
 }
 
 void securitySystem(int rooms, int locks[]) {
     int room;
     printf("Enter room number to Lock/Unlock (1-%d): ", rooms);
     scanf("%d", &room);
     
     if (room >= 1 && room <= rooms) {
         locks[room - 1] = !locks[room - 1];  // Toggle lock status
         printf("Room %d is now %s.\n", room, locks[room - 1] ? "LOCKED" : "UNLOCKED");
     } else {
         printf("Invalid room number!\n");
     }
 }
 
 void analyzeHouseStatus(int rooms, int lights[], int locks[], int motion[], int temperature[]) {
     printf("\n===== House Status Summary =====\n");
     for (int i = 0; i < rooms; i++) {
         printf("Room %d:\n", i + 1);
         printf("  Light: %s\n", lights[i] ? "ON" : "OFF");
         printf("  Lock: %s\n", locks[i] ? "LOCKED" : "UNLOCKED");
         printf("  Motion Detected: %s\n", motion[i] ? "YES" : "NO");
         printf("  Temperature: %d°C\n", temperature[i]);
     }
     printf("=================================\n");
 }
 