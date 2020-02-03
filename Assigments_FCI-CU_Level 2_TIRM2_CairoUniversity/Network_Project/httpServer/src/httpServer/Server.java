package httpServer;


import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.HttpURLConnection;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.URL;
import java.io.File;



public class Server {
	public static void main(String[] args) throws IOException  
    { 
        // server is listening on port  
      ServerSocket ss = new ServerSocket(55067); 
      while(true) { 
            Socket socket = null; 
              
            try 
            {
                // socket object to receive incoming client requests 
            	socket = ss.accept(); 
                  
                System.out.println("A new client is connected : " + socket); 
                                  
                System.out.println("Assigning new thread for this client"); 
  
                // create a new thread object 
                Thread t = new ClientHandler(socket); 
  
                // Invoking the start() method 
                t.start(); 
            } 
            catch (Exception e){ 
            	socket.close(); 
                e.printStackTrace(); 
            } 
        }
    }
   
} 
  

// ClientHandler class 
class ClientHandler extends Thread  
{ 
    final Socket s;
	private BufferedReader input; 
	private DataInputStream in;
    // Constructor 
    public ClientHandler(Socket s)  
    { 
        this.s = s; 
    } 
    
    public void run()  
    { 
    	
    	
    	String massege;
    	StringBuilder stringbuilder = new StringBuilder();
    	//StringBuffer Response = new StringBuffer();
    		try{
    			in = new DataInputStream(s.getInputStream());
    			if ((massege = in.readUTF()) != null )
    				{
    				stringbuilder.append(massege);
    				}
                String mass = stringbuilder.toString();
                System.out.println("Message Received: " + mass);
                
                
                //--------------------
                URL urlForGetRequest = new URL(mass);
                //String readUTF = null;
                String readLine = null;
                HttpURLConnection conection = (HttpURLConnection) urlForGetRequest.openConnection();
                conection.setRequestMethod("GET");
                int responseCode = conection.getResponseCode();
                if (responseCode == HttpURLConnection.HTTP_OK) {
                	BufferedReader in = new BufferedReader(
                    new InputStreamReader(conection.getInputStream()));
                    StringBuffer response = new StringBuffer();
                    while ((readLine = in.readLine()) != null) {
                                response.append(readLine);
                     } in.close();
                     String k = response.toString();
                    System.out.println(k);
                    StringBuilder FileNameBuilder = new StringBuilder();
                    String SocketIPAddress = s.getRemoteSocketAddress().toString().replace("/","").replace(":","");
                    String txt = ".txt";
                    FileNameBuilder.append(SocketIPAddress);
                    FileNameBuilder.append(txt);
                    String fileName = FileNameBuilder.toString(); 
                    try {
                        // Assume default encoding.
                    	File file = new File(fileName);
                    	file.createNewFile();
                    	
                        FileWriter fileWriter = new FileWriter(file);
                    	String FilePath= file.getAbsolutePath();
                        // Always wrap FileWriter in BufferedWriter.
                        BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);

                        // Note that write() does not automatically
                        // append a newline character.
                        bufferedWriter.write(response.toString());
                        bufferedWriter.close();
                        //ObjectOutputStream oos = new ObjectOutputStream(s.getOutputStream());
                        //write object to Socket
                        DataOutputStream DataOut = new DataOutputStream(s.getOutputStream());
                        //oos.writeChars(FilePath);
                        DataOut.writeUTF(FilePath);
                        //oos.close();
                        DataOut.close();
                        s.close();
                    }
                    catch(IOException ex) {
                        System.out.println("Error writing to file " + fileName + "'");
                        // Or we could just do this:
                        // ex.printStackTrace();
                    }
                 
                } else {
                    System.out.println("GET NOT WORKED");
                }
    		
    
    		}catch (Exception e){ 
            	try {
					s.close();
				} catch (IOException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				} 
                e.printStackTrace(); 
            }
         } 
      //}
} 