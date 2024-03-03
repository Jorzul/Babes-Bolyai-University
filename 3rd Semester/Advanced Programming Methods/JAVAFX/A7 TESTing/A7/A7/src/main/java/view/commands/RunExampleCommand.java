package view.commands;

import controller.Controller;

import java.util.List;

public class RunExampleCommand extends Command{
    Controller ctr;
    public RunExampleCommand(String key, String description, Controller ctr){
        super(key, description);
        this.ctr = ctr;
    }

    @Override
    public void execute() {
        try{
            ctr.allStep();
        } catch(Exception e){
            System.out.println(e.getMessage());
        }
    }
}
