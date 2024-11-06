import java.util.Scanner;

class Position {
    String word;
    int value;

    public Position(String word, int value) {
        this.word = word;
        this.value = value;
    }
}

public class Main {

    public static boolean procuraPalavra(Position[] positions, String palavra, int numWords, int[] posicao) {
        for (int i = 0; i < numWords; i++) {
            if (positions[i].word.equals(palavra)) {
                posicao[0] = i;
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int numberWords = scanner.nextInt();
        int numberDescriptions = scanner.nextInt();
        scanner.nextLine(); // Consome a linha restante após a entrada dos inteiros

        Position[] positions = new Position[1000];
        for (int i = 0; i < numberWords; i++) {
            String word = scanner.next();
            int value = scanner.nextInt();
            positions[i] = new Position(word, value);
            scanner.nextLine(); // Consome a linha restante após a entrada do valor
        }

        while (numberDescriptions-- > 0) {
            int totalSalary = 0;
            String[] dictionary = new String[10000];
            int wordIndex = 0;
            
            String line = scanner.nextLine();
            while (!line.equals(".")) {
                String[] words = line.split(" ");
                for (String word : words) {
                    dictionary[wordIndex++] = word;
                }
            }

            int[] posicao = new int[1];
            for (int j = 0; j < wordIndex; j++) {
                if (procuraPalavra(positions, dictionary[j], numberWords, posicao)) {
                    totalSalary += positions[posicao[0]].value;
                }
            }

            System.out.println(totalSalary);
        }

        scanner.close();
    }
}
