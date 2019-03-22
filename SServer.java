import java.io.*;
import java.net.*;

public class SServer{
	public static void main(String args[]) throws IOException{
		ServerSocket serverSocket = new ServerSocket(10000);
		Socket clientSocket = serverSocket.accept();
		
			System.out.println("client connected");
		InputStreamReader gt = new 
InputStreamReader(clientSocket.getInputStream());
		BufferedReader ot=new BufferedReader (gt);

		PrintWriter rp = new 
PrintWriter(clientSocket.getOutputStream());
		rp.println("Wo Hen Hao");
		rp.flush();

		String recvr = ot.readLine();
System.out.println(recvr);
}
}
		
