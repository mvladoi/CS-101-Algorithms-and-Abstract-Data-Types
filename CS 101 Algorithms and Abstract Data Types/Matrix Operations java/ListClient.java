


import java.io.*;
import java.util.Scanner;

public class ListClient {

	 public static void main(String[] args)throws IOException{
	      Scanner in = null;
	      PrintWriter out = null;
	      String line = null;
	      int size, entriesA, entriesB, lines = 0;
	      double [][] data;

	      if(args.length < 2){
	         System.err.println("Usage: FileIO infile outfile");
	         System.exit(1);
	      }

	      in = new Scanner(new File(args[0]));
	      out = new PrintWriter(new FileWriter(args[1]));


	      BufferedReader reader = new BufferedReader(new FileReader(args[0]));

	  	  while (reader.readLine() != null) {
	  		  lines++;
		  }
	         reader.close();


		 data = new double [lines][3];
	     int k = -1;
	     String arr;

		 	  	 while(in.hasNextLine() ){
		         arr = in.nextLine();
		         String[] values = arr.split(" ");
		         double[] dValues = new double[3];
		         if(values.length == 3){

                     dValues[0] = Double.parseDouble(values[0]);
                     dValues[1] = Double.parseDouble(values[1]);
                     dValues[2] = Double.parseDouble(values[2]);
                     data[++k] = dValues;

			    }

		       }




           size = (int)data[0][0];
           entriesA = (int)data[0][1];
           entriesB = (int)data[0][2];
           Matrix A = new Matrix (size);
           Matrix B = new Matrix (size);




		       for (int a = 1; a <= entriesA; a++){

				   A.changeEntry((int)data[a][0], (int)data[a][1], data[a][2]);
			   }


			   for (int b = entriesA+1; b <= entriesB + entriesA; b++){

			   				   B.changeEntry((int)data[b][0], (int)data[b][1], data[b][2]);
			   }



	      out.println(A.getNNZ());
	      out.println(A);

	      out.println(B.getNNZ());
	      out.println(B);

	      Matrix C = A.scalarMult(1.5);
	      out.println(C.getNNZ());
	      out.println(C);

	      Matrix D = A.add(A);
	      out.println(D.getNNZ());
	      out.println(D);

	      Matrix E = A.sub(A);
	      out.println(E.getNNZ());
	      out.println(E);

	      Matrix F = B.transpose();
	      out.println(F.getNNZ());
	      out.println(F);
	      out.println(B);




	      Matrix G = B.mult(B);
	      out.println(G.getNNZ());
	      out.println(G);

	      Matrix H = A.copy();
	      out.println(H.getNNZ());
	      out.println(H);
	      out.println(A.equals(H));
	      out.println(A.equals(B));
	      out.println(A.equals(A));

	      A.makeZero();
	      out.println(A.getNNZ());
	      out.println(A);



                 in.close();
			   	 out.close();
}
}