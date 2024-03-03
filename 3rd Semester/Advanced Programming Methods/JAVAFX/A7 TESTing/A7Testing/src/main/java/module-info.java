module com.example.a7testing {
    requires javafx.controls;
    requires javafx.fxml;

    requires org.controlsfx.controls;
    requires com.dlsc.formsfx;

    opens com.example.a7testing to javafx.fxml;
    exports com.example.a7testing;
}