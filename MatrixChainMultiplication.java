/**
 * @file MatrixChainMultiplication.java
 * @author 
 * @brief 
 * @version 0.1
 * @date 2020-09-08
 * 
 * @copyright Instituto Tecnológico de Aeronáutica. Copyright (c) 2020
 * 
 */

//Class containing 'main' method
public class MatrixChainMultiplication {
 
    public static void main(String[] args) throws Exception {
 
        //Creating A1, A2, A3 & A4 
        Matrix matrices[] = {new Matrix(5,4),
                new Matrix(4,6),
                new Matrix(6,2),
                new Matrix(2,7)};
 
        MatrixChain matrixChain = new MatrixChain(matrices);
        int multiplications = matrixChain.solve();
 
        //Printing 2D array (memoize table)
        for(int i=0; i<matrices.length; i++){
 
            for(int j=0; j<matrices.length; j++){
 
                System.out.print(matrixChain.matrixMulCount[i][j]+ "\t");
            }
 
            System.out.println();
 
        }
 
        System.out.println("Minimum multiplications required: "+multiplications);
    }
}
 
class Matrix {
    int row;
    int col;
 
    public Matrix(int row, int col) {
        this.row = row;
        this.col = col;
    }
}
 
//Algorithm class
class MatrixChain {
    int numberOfMatrices;
    Matrix matrices[];
    int matrixMulCount[][];
 
    public MatrixChain(Matrix[] matrices) {
        this.matrices = matrices;
        this.numberOfMatrices = matrices.length;
        matrixMulCount = new int[this.numberOfMatrices][this.numberOfMatrices];
    }
 
    //Solving matrix chain multiplication using dynamic programming
    public int solve(){
 
        for(int k=1; k<numberOfMatrices; k++){
 
            for(int i=0; i<numberOfMatrices; i++){
 
                if(i+k >= numberOfMatrices) break;
 
                //matrixMulCount[i][i+k]
 
                matrixMulCount[i][i+k] = matrixMulCount[i][i]
                                        + matrixMulCount[i+1][i+k]
                                        + matrices[i].row * matrices[i].col * matrices[i+k].col;
 
                for(int j=i+1; j<i+k; j++){
 
                    matrixMulCount[i][i+k]= Integer.min(matrixMulCount[i][i+k],
                            matrixMulCount[i][j] + matrixMulCount[j+1][i+k]
                                    +( j+1 == i+k ? ( matrices[i].row * matrices[i+k].row * matrices[i+k].col): (matrices[i].row * matrices[j].col * matrices[i+k].col)));
 
                }
            }
        }
        return matrixMulCount[0][numberOfMatrices-1];
    }
}
 
