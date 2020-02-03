package httpClient;

import java.io.*; 
import java.net.*; 
import java.util.Scanner;
import java.awt.Desktop;
 
// Client class 
public class Client
{ 
    public static void main(String[] args) throws IOException  
    { 
        try
        { 
            Scanner scn = new Scanner(System.in);
              
            // getting localhost ip 
            InetAddress ip = InetAddress.getByName("localhost"); 
      
            // establish the connection with server port  
            Socket s = new Socket(ip, 55067); 
      
            // obtaining input and out streams 
            DataInputStream dis = new DataInputStream(s.getInputStream()); 
            DataOutputStream dos = new DataOutputStream(s.getOutputStream()); 
      
                System.out.println("Sending url ...");
                System.out.println("https://www.google.com/");
                dos.writeUTF("https://www.google.com/\n");
                
                DataInputStream DataInput = new DataInputStream(s.getInputStream());
                BufferedReader input;
                //ObjectInputStream  
                //input = new BufferedReader(new InputStreamReader(s.getInputStream()));
                String fileName = DataInput.readUTF();
                String path = fileName.toString();
                System.out.println("Receving the path of file ..." + path);
                
                try {
                    // Use this for reading the data.
                    byte[] buffer = new byte[10000];

                    
                    FileInputStream inputStream = 
                    new FileInputStream(fileName);
                    File file = new File(fileName);
                    Desktop desktop = Desktop.getDesktop();
                    desktop.open(file);
                    
                    BufferedReader br = new BufferedReader(new FileReader(fileName));
                    String st; 
                    while ((st = br.readLine()) != null) 
                      System.out.println(st); 
                    // read fills buffer with data and returns
                    // the number of bytes read (which of course
                    // may be less than the buffer size, but
                    // it will never be more).
                    int total = 0;
                    int nRead = 0;
                    while((nRead = inputStream.read(buffer)) != -1) {
                        // Convert to String so we can display it.
                        // Of course you wouldn't want to do this with
                        // a 'real' binary file 
                	    System.out.println(new String(buffer));
                        total += nRead;
                    }   
                    // Always close files.
                    inputStream.close();        
                    System.out.println("Read " + total + " bytes");
                }
                catch(FileNotFoundException ex) {
                    System.out.println("Unable to open file '" + fileName + "'");                
                }
                catch(IOException ex) {
                    System.out.println("Error reading file '" + fileName + "'");                  
                    // Or we could just do this: 
                    // ex.printStackTrace();
                }
           // }
              
            // closing resources 
            scn.close(); 
            dis.close(); 
            dos.close(); 
        }catch(Exception e){ 
            e.printStackTrace(); 
        } 
    } 
}