package View;

import controller.Controller;
import model.*;
import java.util.Scanner;

public class View {
    private Controller controller;

    public View(Controller controller) {
        this.controller = controller;
    }

    public void printMenu(){
        System.out.println("MAIN MENU.");
        System.out.println("1. Add");
        System.out.println("2. Remove");
        System.out.println("3. All");
        System.out.println("4. Filter");
        System.out.println("0. Exit");
    };
    public void run(){
        while (true)
        {
            printMenu();
            String option = readOption();

            if (option.equals("0"))
            {
                System.out.println("Ending system.");
                break;
            }

            switch(option) {
                case "1":
                {
                    add_item_menu();
                    break;
                }
                case "2":
                {
                    remove_item_menu();
                    break;

                }
                case "3":
                {
                    Item[] all_items = controller.all();
                    for (Item i : all_items)
                    {
                        if (i != null)
                        {
                            System.out.println("Type: " + i.getType() + " | Volume: " + i.getVolume());
                        }
                    }
                    break;
                }
                case "4":
                {
                    filter_item_menu();
                    break;
                }
            }
        }
    }
    public String readOption()
    {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Give option: ");
        return scanner.nextLine();
    }

    public void add_item_menu()
    {
        System.out.println("What item would you like to add?");
        System.out.println("1. Cub");
        System.out.println("2. Sfera");
        System.out.println("3. Cilindru");

        Scanner scanner = new Scanner(System.in);
        String add_option = scanner.nextLine();

        if (add_option.equals("1"))
        {
            System.out.println("Give a value(cub): ");

            float x = Float.parseFloat(scanner.nextLine());
            controller.add(new Cub(x));
        }
        else if (add_option.equals("2"))
        {
            System.out.println("Give a value(sfera): ");

            float x = Float.parseFloat(scanner.nextLine());
            controller.add(new Sfera(x));
        }
        else if (add_option.equals("3"))
        {
            System.out.println("Give a value(cilindru): ");

            float x = Float.parseFloat(scanner.nextLine());
            controller.add(new Cilindru(x));
        }
        else
            System.out.println("Invalid command");
    }

    public void remove_item_menu()
    {
        System.out.println("Give a value: ");
        Scanner scanner = new Scanner(System.in);

        float x = Float.parseFloat(scanner.nextLine());

        Item[] all_items = controller.all();
        for (Item i : all_items)
        {
            if (i != null && i.getVolume() == x)
            {
                controller.remove(i);
                System.out.println("Item removed successfully");
                break;
            }
            else if (i == null)
            {
                System.out.println("Item does not exist.");
                break;
            }
        }
    }

    public void filter_item_menu()
    {
        System.out.println("Give a value: ");
        Scanner scanner = new Scanner(System.in);
        //scanner.nextFloat();
        float x = Float.parseFloat(scanner.nextLine());
        Item[] filteredItems = controller.filter(x);
        for (Item i : filteredItems)
        {
            if (i != null)
                System.out.println("Type: " + i.getType() + " | Volume: " + i.getVolume());
        }
    }
}
