package pack;

import java.io.File;
import java.io.IOException;
import java.util.List;
import java.util.Scanner;



public class RepoAnalyzer {

	public static void main(String[] args) {
	
		//usage java -jar Program.jar
		Utils utils=new Utils();
	
        Scanner scanner = new Scanner(System.in);

        System.out.println("Please enter the GitHub Repository URL:  ");
        String repoUrl = scanner.nextLine();
        scanner.close();

        try {
            // Klonlama
        	utils.cloneRepository(repoUrl);//

            // Java dosyalarını bulma
            File repoDirectory = new File(System.getProperty("user.dir"));
            List<File> javaFiles = utils.findJavaFiles(repoDirectory);//tum .java files 
           
            // Java dosyalarını listeleme
            System.out.println("================================");
            System.out.println("All Files with '.java' extension");
            System.out.println("================================");
            for (File javaFile : javaFiles) {
                String fileName = javaFile.getName();
                System.out.println(fileName);
            }

            // Class dosyalarını bulma
            List<File> classFiles = utils.findClassFiles(utils.findJavaFiles(repoDirectory));

            // Class dosyalarını listeleme
            System.out.println("==============================");
            System.out.println("Classes:");
            System.out.println("==============================");
            for (File classFile : classFiles) {
                String fileName = classFile.getName();
                System.out.println(fileName);
            }
            System.out.println("==============================");
           
        
           // Class icine gir
         for (File classFile : classFiles) {
            	
        	 	System.out.println("-----------------------------------------");
        	 	System.out.println("Sınıf: " + classFile.getName());
                System.out.println("Javadoc Satır Sayısı: " + utils.javadocCount(classFile));
               // System.out.println("'//' Yorum Satır Sayısı: " + utils.countSingleCommentLinesTypeOne(classFile));
               // System.out.println("'/*  */' Yorum Satır Sayısı: " + utils.countSingleCommentLinesTypeTwo(classFile));
                System.out.println("Yorum Satır Sayısı: " +utils.totalSingleCommentLines(classFile));
                System.out.println("Kod Satır Sayısı: " + utils.getCodeLineCount(classFile));
                System.out.println("LOC: "  +utils.locCount(classFile));//bosluk dahil her sey sayisi 
                System.out.println("Fonksiyon Sayısı: " + utils.functionCount(classFile));
                System.out.println("Yorum Sapma Yüzdesi:% "+utils.yorumSapmaYuzdesi(classFile));
                System.out.println("-----------------------------------------");
            }
            
        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        }
        
        
        
  
		
		

	}

}
