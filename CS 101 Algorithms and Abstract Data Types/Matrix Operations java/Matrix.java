


public class Matrix extends List {


	private int size;
	private int NNZ;
	List<Entry>[] row = null;

	class Entry {
		private double value;
		private int col;

		int getCol() {
			return col;
		}

		Entry(int col, double value) {
			this.value = value;
			this.col = col;
		}

		Entry(Entry newEntry) {
			this.col = newEntry.col;
			this.value = newEntry.value;
		}

		public boolean equals(Object x) {
			boolean eq = false;
			Entry that;
			if (x instanceof Entry) {
				that = (Entry) x;
				eq = ((this.value == that.value) && (this.col == that.col));
			}
			return eq;
		}

		public String toString() {
			StringBuffer sb = new StringBuffer();
			sb.append("(" + String.valueOf(col) + " " + String.valueOf(value) + ")" + " ");
			return new String(sb);
		}
	}

	Matrix(int n) {
		row = (List<Entry>[]) new List[n + 1];
		for (int i = 0; i < n + 1; i++) {
			row[i] = new List<>();
		}
		size = n;
		NNZ = 0;
	}

	// Access functions

	// Returns n, the number of rows and columns of this Matrix
	int getSize() {
		return size;
	}

	// Returns the number of non-zero entries in this Matrix
	int getNNZ() {
		return NNZ;
	}

	// public boolean equals(Object x) // overrides Object's equals() method
	public boolean equals(Object x) {
		boolean eq = false;

		Matrix L;

		if (x instanceof Matrix) {
			L = (Matrix) x;
			if (this.getSize() != L.getSize())
				return false;
			for (int i = 1; i <= size; i++) {
				eq = (this.row[i].equals(L.row[i]));
				if (!eq)
					return false;
			}
		}
		return true;
	}

	// Manipulation procedures

	// sets this Matrix to the zero state
	void makeZero() {
		for (int i = 0; i < size + 1; i++) {
			row[i].clear();
		}
		NNZ = 0;
	}

	// returns a new Matrix having the same entries as this Matrix
	Matrix copy() {
		Matrix newMatrix = new Matrix(size);
		for (int s = 1; s < size + 1; s++) {
			// List<Entry> temp = row[s].copy();
			if(!row[s].isEmpty()){
				row[s].moveFront();
			for (int j = 0; j < row[s].length(); j++){

				Entry temp = row[s].get();

			newMatrix.changeEntry(s, temp.col, temp.value);
			row[s].moveNext();

		}
	}
}

		newMatrix.size = this.size;
		newMatrix.NNZ = this.NNZ;
		return newMatrix;
	}

	// changes ith row, jth column of this Matrix to x
	// pre: 1<=i<=getSize(), 1<=j<=getSize()
	void changeEntry(int i, int j, double x) {

		if ((i < 1) || (i > getSize())) {
			throw new RuntimeException("Matrix Error: changeEntry() called on i out of bound");
		}

		if ((j < 1) || (j > getSize())) {
			throw new RuntimeException("Matrix Error: changeEntry() called on j out of bound");
		}

		Entry newEntry = new Entry(j, x);

		if (row[i].isEmpty() == true) {
			row[i].prepend(newEntry);
			NNZ++;
		}

		boolean insert = false;
		for (row[i].moveFront(); row[i].index() >= 0; row[i].moveNext()) {

			Entry temp = (Entry) row[i].get();

			if (temp.col == newEntry.col) {

				if (x == 0) {
					row[i].delete();
					NNZ--;
					insert = true;
				}

				if (x != 0) {
					temp.value = x;
					insert = true;
				}

			}

			if ((temp.col > j) && (!insert)) {
				row[i].insertBefore(newEntry);
				insert = true;
				NNZ++;
			}

		}
		if ((!insert) && (x != 0)) {
			row[i].append(newEntry);
			NNZ++;
		}

	}

	// returns a new Matrix that is the scalar product of this Matrix with x
	Matrix scalarMult(double x) {
		Matrix newMatrix = new Matrix(size);
		for (int s = 1; s <= size; s++) {
			for (row[s].moveFront(); row[s].index() >= 0; row[s].moveNext()) {
				Entry temp = new Entry(row[s].get());
				temp.value = temp.value * x;
				newMatrix.row[s].append(temp);
			}
		}
		newMatrix.NNZ = this.NNZ;
		return newMatrix;
	}

	// Matrix add(Matrix M)
	// returns a new Matrix that is the sum of this Matrix with M
	// pre: getSize()==M.getSize()

	Matrix add(Matrix M) {
		if (this.getSize() != M.getSize()) {
			throw new RuntimeException("Matrix Error: add() called on  2 matrices with different size");
		}

		Matrix newMatrix = new Matrix(size);

		if (this.equals(M)) {
			M = M.copy();
		}

		for (int s = 1; s <= size; s++) {

			int j;
			int p = row[s].length();
			int r = M.row[s].length();

			if (p <= r) {
				j = r;
			} else
				j = p;

			row[s].moveFront();
			M.row[s].moveFront();
			for (int i = 0; i < 2 * j; i++) {
				if ((row[s].index() == -1) && (M.row[s].index() == -1))
					break;

				Entry temp;
				Entry temp2;

				if ((row[s].index() != -1) && (M.row[s].index() != -1)) {

					temp = new Entry(row[s].get());
					temp2 = new Entry(M.row[s].get());
					if (temp2.col == temp.col) {
						temp.value = temp.value + temp2.value;
						newMatrix.changeEntry(s, temp.col, temp.value);
						M.row[s].moveNext();
						row[s].moveNext();
					}

					else if (temp.col < temp2.col) {
						newMatrix.changeEntry(s, temp.col, temp.value);
						row[s].moveNext();
					}

					else {
						newMatrix.changeEntry(s, temp2.col, temp2.value);
						M.row[s].moveNext();
					}

				}

				else if (row[s].index() == -1) {
					temp = new Entry(M.row[s].get());
					newMatrix.changeEntry(s, temp.col, temp.value);
					M.row[s].moveNext();

				}

				else if (M.row[s].index() == -1) {
					temp = new Entry(row[s].get());
					newMatrix.changeEntry(s, temp.col, temp.value);
					M.row[s].moveNext();

				}

			}
		}

		return newMatrix;
	}

	// Matrix sub(Matrix M)
	// returns a new Matrix that is the sum of this Matrix with M
	// pre: getSize()==M.getSize()

	Matrix sub(Matrix M) {
		if (this.getSize() != M.getSize()) {
			throw new RuntimeException("Matrix Error: sub() called on  2 matrices with different size");
		}

		Matrix newMatrix = new Matrix(size);

		if (this.equals(M)) {
			return newMatrix;
		}

		for (int s = 1; s <= size; s++) {

			int j;
			int p = row[s].length();
			int r = M.row[s].length();

			if (p <= r) {
				j = r;
			} else
				j = p;

			row[s].moveFront();
			M.row[s].moveFront();
			for (int i = 0; i < 2 * j; i++) {
				if ((row[s].index() == -1) && (M.row[s].index() == -1))
					break;

				Entry temp;
				Entry temp2;

				if ((row[s].index() != -1) && (M.row[s].index() != -1)) {

					temp = new Entry(row[s].get());
					temp2 = new Entry(M.row[s].get());
					if (temp2.col == temp.col) {
						temp.value = temp.value - temp2.value;
						if (temp.value != 0) {
							newMatrix.changeEntry(s, temp.col, temp.value);
						}
						M.row[s].moveNext();
						row[s].moveNext();
					}

					else if (temp.col < temp2.col) {
						if (temp.value != 0) {
							newMatrix.changeEntry(s, temp.col, temp.value);
						}
						row[s].moveNext();
					}

					else {

						temp2.value = -temp2.value;
						if (temp.value != 0) {
							newMatrix.changeEntry(s, temp2.col, temp2.value);

						}
						M.row[s].moveNext();
					}

				}

				else if (row[s].index() == -1) {
					temp = new Entry(M.row[s].get());
					temp.value = -temp.value;
					if (temp.value != 0) {
						newMatrix.changeEntry(s, temp.col, temp.value);
					}
					M.row[s].moveNext();

				}

				else if (M.row[s].index() == -1) {
					temp = new Entry(row[s].get());
					if (temp.value != 0) {
						newMatrix.changeEntry(s, temp.col, temp.value);
						;

					}
					M.row[s].moveNext();

				}

			}
		}

		return newMatrix;
	}

	// Matrix transpose()
	// returns a new Matrix that is the transpose of this Matrix
	Matrix transpose() {
		Matrix B = new Matrix(size);
		for (int i = 1; i <= size; i++) {
			for (row[i].moveFront(); row[i].index() >= 0; row[i].moveNext()) {
				Entry temp = new Entry(row[i].get());
				B.changeEntry(temp.col, i, temp.value);
			}
		}
		return B;

	}

	// Matrix mult(Matrix M)
	// returns a new Matrix that is the product of this Matrix with M
	// pre: getSize()==M.getSize()

	Matrix mult(Matrix M) {
		if (this.getSize() != M.getSize()) {
			throw new RuntimeException("Matrix Error: mult() called on  2 matrices with different size");
		}

		Matrix newMatrix = new Matrix(size);

		if (this.equals(M)) {
			M = M.copy();
		}

		Matrix T = M.transpose();

		for (int i = 1; i <= size; i++) {
			for (int j = 1; j <= this.size; j++) {
				double sum = dot(this.row[i], T.row[j]);
				newMatrix.changeEntry(i, j, sum);
			}

		}
		return newMatrix;

	}

	// Other functions
	// overrides Object's toString() method
	public String toString() {
		if (this.getNNZ() == 0)
			return "";
		StringBuffer sb = new StringBuffer();
		for (int k = 1; k < size + 1; k++) {
            if(!row[k].isEmpty()){
			sb.append(String.valueOf(k) + ": ");
			sb.append(row[k].toString());
			sb.append("\n");
            }
		}

		return new String(sb);
	}




	private static double dot(List<Entry> P, List<Entry> R) {
		double sum = 0;
		if (P.isEmpty() || R.isEmpty())
			return sum;

		int j = 0;
		Entry temp;
		Entry temp2;

		int p = P.length();
		int r = R.length();

		if (p <= r) {
			j = r;
		} else
			j = p;

		R.moveFront();
		P.moveFront();

		for (int i = 1; i <= 2 * j; i++) {

			if ((P.index() != -1) && (R.index() != -1)) {
				temp = P.get();
				temp2 = R.get();

				if (temp2.col == temp.col) {
					sum += temp.value * temp2.value;
					R.moveNext();
					P.moveNext();
				}

				else if (temp.col > temp2.col) {
					R.moveNext();
				}

				else if (temp.col < temp2.col) {
					P.moveNext();
				}
			}
		}


		return sum;
	}

}