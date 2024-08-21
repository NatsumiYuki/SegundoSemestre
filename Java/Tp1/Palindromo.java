
import java.util.Scanner;

public class Palindromo {
    public static void main(String[] args){
        try (Scanner sc = new Scanner(System.in)) {
            String palavra = sc.nextLine();
        while (!palavra.equals("FIM")){
            boolean ePalindromo = verificarPalindromo(palavra);
            if (ePalindromo) {
                System.out.print("SIM\n");
            } else {
                System.out.print("NAO\n");
            }
            palavra = sc.nextLine(); 
        }
      }
    }

    private static boolean verificarPalindromo(String palavra){
        StringBuilder palavraInversa = new StringBuilder(palavra).reverse();
        return palavra.equals(palavraInversa.toString());
    }
}
