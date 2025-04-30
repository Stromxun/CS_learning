public class HelloGoodbye {
    public static void main(String[] args) {
        assert args.length == 2;
        String name1 = args[0], name2 = args[1];
        System.out.println("Hello " + name1 + " and " + name2 + ".");
        System.out.println("Goodbye " + name2 + " and " + name1 + ".");
    }
}
