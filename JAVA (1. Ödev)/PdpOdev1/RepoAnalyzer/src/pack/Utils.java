package pack;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;



public class Utils {

 	//tüm dosyalar arasından .java dosyalari ayikla ör .c uzantili dosyalari alma
 	public  List<File> findJavaFiles(File directory) throws IOException {
        List<File> javaFiles = new ArrayList<>();
        findJavaFilesHelper(directory, javaFiles);
        return javaFiles;
    }
 	
 	
    //.java dosyalari ayiklama helper  
    public  void findJavaFilesHelper(File directory, List<File> javaFiles) throws IOException {
        File[] files = directory.listFiles();
        if (files != null) {
            for (File file : files) {
                if (file.isDirectory()) {
                    findJavaFilesHelper(file, javaFiles);
                } else if (file.getName().endsWith(".java")) {
                    javaFiles.add(file);
                }
            }
        } else {
            throw new IOException("Error accessing directory: " + directory.getAbsolutePath());
        }
    }

    //Dosyalar arasından Classlari Ayıkla 
   	public List<File> findClassFiles(List<File> javaFiles) {
   	    List<File> classFiles = new ArrayList<>();
   	    for (File javaFile : javaFiles) {
   	        boolean isClass = false;
   	        boolean hasInterface = false;
   	        try (Scanner scanner = new Scanner(javaFile)) {
   	            while (scanner.hasNextLine()) {
   	                String line = scanner.nextLine();
   	                if (line.toLowerCase().contains("class")){
   	                    isClass = true;
   	                   
   	                }if (line.toLowerCase().contains("interface")) {
   	                    hasInterface = true;
   	                }
   	            }
   	        } catch (FileNotFoundException e) {
   	            e.printStackTrace();
   	        }

   	        if (isClass && !hasInterface) {
   	            classFiles.add(javaFile);
   	        }
   	    }
   	    return classFiles;
   	}  
   	 
   	//Repo Klonla
    public  void cloneRepository(String repoUrl) throws IOException, InterruptedException {
    	
        ProcessBuilder processBuilder = new ProcessBuilder();
        processBuilder.command("git","clone", repoUrl);
        Process process = processBuilder.start();
        process.waitFor();
    }
    //function count  checked  //double checked
    public  int functionCount(File file) {
        int count = 0;
        try (Scanner scanner = new Scanner(file)) {
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                if (line.contains("public") && line.contains("(") || line.contains("private") && line.contains("(") || line.contains("protected") && line.contains("(")||line.contains("void")&&line.contains("(") ) {
                    count++;
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return count;
    }

    //LOC checked  //doubleChecked
    public  int locCount(File file) {

    	 int count = 0;
    	    try (Scanner scanner = new Scanner(file)) {
    	        while (scanner.hasNextLine()) {
    	            scanner.nextLine();
    	            count++;
    	        }
    	    } catch (IOException e) {
    	        e.printStackTrace();
    	    }
      
        return count;
    }
    
    //Java doc count checked //double checked
    public  int javadocCount(File file) {
    	  int count = 0;
    	  boolean inJavadoc = false;
    	  try (Scanner scanner = new Scanner(file)) {
    	    while (scanner.hasNextLine()) {
    	      String line = scanner.nextLine();
    	      if (line.contains("/**")) {   //AÇ
    	        inJavadoc = true;
    	        
    	      } else if (inJavadoc && line.contains("*/")) { //KAPAT
    	        inJavadoc = false;
    	       
    	      } else if (inJavadoc) {//DEGERİ ARTTIR
    	        count++;
    	      }
    	    }
    	    
    	  } catch (IOException e) {
    	    e.printStackTrace();
    	  }
    	  return count;
    	}
    
    
    //##SINLE COMMENTS SECTION
    // '//' single comment count checked //double checked
    public  int countSingleCommentLinesTypeOne(File file) throws IOException {
        int count = 0;
        try (Scanner scanner = new Scanner(file)) {
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                
                if(line.trim().startsWith("*")&&line.contains("//")||line.contains("(\"//\")")) 
                {
                	//if line starts with * and contains '//' character
                	//or line contains  System.out.println("//") this is not comment
                	continue;	
                }
                if (line.trim().startsWith("//")||(!line.trim().startsWith("//")&&line.contains("//"))) {
                    count++;
                }
            }
        }
        return count;
    }	    
    // /* */ single comment count checked //double checked
    public  int countSingleCommentLinesTypeTwo(File file) {
        int count = 0;
        boolean incomment = false;
        boolean started = false;

        try (Scanner scanner = new Scanner(file)) {
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                

                if (line.contains("/*") && !line.contains("/**")) {
                	incomment = true;
                    started = true; //basla
                    
                    
                }
                //  if comment type like this  ' /* comment */ '
                if(incomment && line.startsWith("/*")&&line.contains("*/")) {
                	
                	incomment = false;
                    started = false;
                    continue;
                }  	                
                
                if(incomment&&started&&  (!line.contains("*/"))) 
                {
                	if(!(line.contains("/*") && !line.contains("/**")))// we already increase this(/*) begining of the code 
                		count++;
                	continue;
                	
                }
                if(incomment&&started) //if this block is runing that means we saw the '*/' this is end 
                {
                	incomment = false;
	                started = false;
                	
                }
                
               
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return count;
    }
    //total single comment  checked
    public  int totalSingleCommentLines(File file)  throws IOException {
    	int sum=countSingleCommentLinesTypeOne(file)+countSingleCommentLinesTypeTwo(file);
        return sum;
    }	    

    public int getCodeLineCount(File file) throws IOException
    {
    	
    	 Scanner scanner = new Scanner(file);
    	    int lineCount = 0;
    	    while (scanner.hasNextLine()) {
    	        String line = scanner.nextLine().trim();
    	        if (!line.isEmpty()) { //bosluk degil ise
    	        	
    	        	if (line.startsWith("/**")) {
						continue;
					}
    	        	else if (line.startsWith("*")) {
    	        		continue;
					}
    	        	else if (line.startsWith("/*")) {
    	        		continue;
					}
    	        	else if (line.startsWith("*/")) {
    	        		continue;
					}
    	        	else if (line.startsWith("//")) {
    	        		continue;
					}
    	        	
    	        	lineCount++;
    	        	
    	         }
    	    }
    	    scanner.close();
    	    return lineCount;
    	
    }
    
    
    public double yorumSapmaYuzdesi(File file) throws IOException
    {
    	double Javadoc_Satir_Sayisi=javadocCount(file);
    	double Diger_yorumlar_satir_sayisi=totalSingleCommentLines(file);
    	double Fonk_Sayisi=functionCount(file);
    	double Kod_satir_sayisi=getCodeLineCount(file);
    	
       double YG =((Javadoc_Satir_Sayisi+Diger_yorumlar_satir_sayisi)*0.8)/Fonk_Sayisi;
       double YH =(Kod_satir_sayisi/Fonk_Sayisi)*0.3;
       
       double sonuc=((100*YG)/YH)-100;
       // Virgülden sonra 2 basamak için Math.round() kullanın
       return Math.round(sonuc * 100) / 100.0;
       
    }
	
	
	
	
	
	
	
	
	
}
