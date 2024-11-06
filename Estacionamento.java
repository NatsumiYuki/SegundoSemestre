import java.util.Scanner;
import java.util.Stack;

public class Estacionamento {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt(); // Número de motoristas
        int k = scanner.nextInt(); // Capacidade do estacionamento

        while (n != 0 || k != 0) {

            Stack<Integer> estacionamento = new Stack<>();
            boolean flag = true;

            for (int i = 0; i < n; i++) {

                int c = scanner.nextInt(); // Hora de chegada do motorista
                int s = scanner.nextInt(); // Hora de saída do motorista

                // Remove todos os carros que saem antes do horário de chegada do carro atual
                while (!estacionamento.isEmpty() && estacionamento.peek() <= c) {
                    estacionamento.pop();
                }

                if (estacionamento.size() >= k) {
                    flag = false;
                } else {
                    if (estacionamento.isEmpty()) {
                        estacionamento.push(s);
                    } else {
                        if (estacionamento.peek() > s) {
                            estacionamento.push(s);
                        } else {
                            flag = false;
                        }
                    }
                }
            }

            // Exibe o resultado para o caso de teste atual
            if (!flag) {
                System.out.println("Nao");
            } else {
                System.out.println("Sim");
            }

            // Lê os valores para o próximo caso de teste
            n = scanner.nextInt();
            k = scanner.nextInt();
        }

        scanner.close();
    }
}
