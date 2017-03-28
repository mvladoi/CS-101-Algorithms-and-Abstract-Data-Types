
import java.io.*;
import java.util.Scanner;


public class ListClient2 {

	public static void main(String[] args) throws IOException{

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




	      out.println( "A has " + A.getNNZ() + " non-zero entries:");
	      out.println(A);
	      out.println();

	      out.println( "B has " + B.getNNZ() + " non-zero entries:");
	      out.println(B);
	      out.println();

	       Matrix C = A.scalarMult(1.5);
	      out.println( "(1.5)*A = :");
	      out.println(C);
	      out.println();


	      Matrix D = B.add(A);
	      out.println( "A+B=  ");
	      out.println(D);
	      out.println();


	      Matrix S = A.add(A);
	      out.println( "A+A = ");
	      out.println(S);
	      out.println();


	      Matrix P = B.sub(A);
	      out.println( "B-A = ");
	      out.println(P);
	      out.println();


	      Matrix R = A.sub(A);
	      out.println( "A-A = ");
	      out.println(R);
	      out.println();


	      Matrix X = A.transpose();
	      out.println( "Transpose(A) = ");
	      out.println(X);
	      out.println();


	      Matrix G = A.mult(B);
	      out.println( "A*B = ");
	      out.println(G);
	      out.println();

	      Matrix Z = B.mult(B);
	      out.println( "B*B = ");
	      out.println(Z);
	      out.println();


                 in.close();
			   	 out.close();


	}
}
