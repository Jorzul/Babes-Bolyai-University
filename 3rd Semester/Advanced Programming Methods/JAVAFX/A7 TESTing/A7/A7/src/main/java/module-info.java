module com.example.a7 {
    requires javafx.controls;
    requires javafx.fxml;

    requires org.controlsfx.controls;
    requires com.dlsc.formsfx;

    opens com.example.a7 to javafx.fxml;
    opens model.ADT to javafx.base;
    exports com.example.a7;
}