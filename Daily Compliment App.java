import javax.swing.JOptionPane;
import java.util.Random;

class DailyComplimentApp {
    public static void main(String[] args) {
        // Array of compliments
        String[] compliments = {
                "You have a great sense of humor!",
                "You are really kind and thoughtful!",
                "You are incredibly talented!",
                "You have a wonderful smile!",
                "You make people feel appreciated!"
        };

        // Welcome message
        JOptionPane.showMessageDialog(null,
                "Welcome to Daily Compliment App!",
                "Welcome",
                JOptionPane.INFORMATION_MESSAGE);

        // Get user's name
        String name = null;
        while (name == null || name.trim().isEmpty()) {
            name = JOptionPane.showInputDialog(null, "Enter your name:");
        }

        // Pick a random compliment
        Random random = new Random();
        int index = random.nextInt(compliments.length);
        String compliment = compliments[index];

        // Motivational speech
        String motivationalSpeech = "Remember, every challenge is an opportunity to grow.\n" +
                "Keep learning, keep coding, and never give up on your dreams!\n" +
                "Your effort today will shape your success tomorrow.";

        // Show compliment + motivational message
        JOptionPane.showMessageDialog(null,
                "Hello " + name + "! Here's your compliment for today:\n" +
                        compliment + "\n\n" +
                        motivationalSpeech,
                "Daily Compliment & Motivation",
                JOptionPane.INFORMATION_MESSAGE);
    }
}