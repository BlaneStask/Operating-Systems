/*
Purpose: This program starts two other processes (Notes and Calculator). 
This program also checks the status of these processes. (on MacOS)
*/ 

package spawn_childprocesses_reqts;
import java.util.*;

public class driver
{ 
	/** This method is the main/driver method
	 * 
	 * @throws Exception e   
	 */
	public static void main(String[] args)
	{
		try 
		{ 
		    // create two new processes 
		    System.out.println("Creating Processes"); 
			
		    // on macOS:
		    // Process p = Runtime.getRuntime().exec("open -Fa calculator");
		    // Process p2 = Runtime.getRuntime().exec("open -Fa notes");
			
		    // on windowsOS:
		    Process p = Runtime.getRuntime().exec("C:\\Windows\\System\\calc.exe");
		    Process p2 = Runtime.getRuntime().exec("C:\\Windows\\System\\notepad.exe");

		    // check if processes are running
		    if(!p.isAlive()) {
			System.out.println("Error calculator process is not running"); 
		    }
		    if(!p2.isAlive()) {
			System.out.println("Error notes process is not running"); 
		    }

		    // wait until processes are terminated
		    p.waitFor();
		    p2.waitFor(); 

		    // checking the exit value of subprocesses 
		    System.out.println("Calculator exit value: " + p.exitValue()); 
		    System.out.println("Notes exit value: " + p2.exitValue()); 
		}  
		catch (Exception e)  
		{ 
		    e.printStackTrace(); 
		} 
	}
}
