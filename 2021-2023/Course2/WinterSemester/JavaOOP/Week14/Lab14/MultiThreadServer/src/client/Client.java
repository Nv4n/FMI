package client;

// Set up a client that will receive a connection from a server, send
// a string to the server, and close the connection.

import java.io.EOFException;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.InetAddress;
import java.net.Socket;
import java.net.SocketException;

import javafx.application.Application;
import javafx.application.Platform;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.stage.Stage;

public class Client extends Application {
    private TextField txtInputLink;
    private TextArea txaChatText;
    private ObjectOutputStream output;
    private ObjectInputStream input;
    private String chatServer;
    private Socket client;


    @Override
    public void start(Stage primaryStage) {
        VBox root = new VBox();
        root.setAlignment(Pos.TOP_CENTER);
        root.setPadding(new Insets(14));
        root.setSpacing(8);
        txtInputLink = new TextField();
        txtInputLink.setPromptText("Type text");
        txaChatText = new TextArea();

        txtInputLink.setEditable(false);

        txtInputLink.setOnAction(event
                        -> {
                    sendData(txtInputLink.getText());
                    txtInputLink.setText("");
                }
        );

        txaChatText.setMaxSize(1.7976931348623157E308, 1.7976931348623157E308);
        root.getChildren().addAll(txtInputLink, txaChatText);
        Scene scene = new Scene(root, 350, 250, Color.web("#666970"));
        // shutdown thread gracefully
        primaryStage.setOnCloseRequest(evt -> stop());
        primaryStage.setTitle("Client");
        primaryStage.setScene(scene);
        primaryStage.show();
        Thread thread = new Thread(this::runClient);
        thread.start();
    }

    // connect to server and process messages from server
    public void runClient() {
        try // connect to server, get streams, process connection
        {
            connectToServer(); // create a Socket to make connection
            getStreams(); // get the input and output streams
            processConnection(); // process connection
        } // end try
        catch (EOFException eofException) {
            displayMessage("\nClient terminated connection");
        } // end catch
        catch (IOException ioException) {
            System.out.println("Client IO exception    " + ioException.getMessage());
        } // end catch
        finally {
            closeConnection(); // close connection
        } // end finally
    } // end method runClient

    // connect to server
    private void connectToServer() throws IOException {
        displayMessage("Attempting connection\n");

        client = new Socket(InetAddress.getByName(chatServer), 12345);

        if (client == null) stop();

        displayMessage("Connected to: "
                + client.getInetAddress().getHostName());
    }

    private void getStreams() throws IOException {
        output = new ObjectOutputStream(client.getOutputStream());
        output.flush();

        input = new ObjectInputStream(client.getInputStream());

        displayMessage("\nGot I/O streams\n");
    }

    private void processConnection() throws IOException {
        String message = "Connection successful";
        sendData(message);

        setTextFieldEditable(true);

        do try {
            message = (String) input.readObject();
            displayMessage("\n" + message);
        } catch (ClassNotFoundException classNotFoundException) {
            displayMessage("\nUnknown object type received");
        } catch (SocketException s) {
            break;
        } while (!message.equalsIgnoreCase("CLIENT>>> TERMINATE"));
    }

    private void closeConnection() {
        displayMessage("\nTerminating connection\n");
        setTextFieldEditable(false);
        try {
            if (output != null) output.close();
            if (input != null) input.close();
            if (client != null) client.close();
        } catch (IOException ioException) {
            ioException.printStackTrace();
        }
    }

    private void sendData(String message) {
        try {
            output.writeObject("CLIENT>>> " + message);
            output.flush(); // flush output to client
            displayMessage("\nCLIENT>>> " + message);
        } catch (IOException ioException) {
            txaChatText.appendText("\nError writing object");
        }
    }

    private void displayMessage(final String messageToDisplay) {
        Platform.runLater(() -> txaChatText.appendText(messageToDisplay));
    }

    private void setTextFieldEditable(final boolean editable) {
        Platform.runLater(() -> txtInputLink.setEditable(editable));
    }

    @Override
    public void stop() {
        Platform.exit();
        System.exit(0);
    }

    public static void main(String[] args) {
        Application.launch(args);
    }

}
