# include <stdlib.h>
# include <gtk/gtk.h>

void load_image(GtkWidget *list[])
{
    /*Initialisation*/

    GtkWidget *window;
    GtkWidget *image;
    GtkWidget *dialog;

    /*Definition*/

    window = list[0];
    image = list[1];
    dialog = gtk_file_chooser_dialog_new("Load Image", GTK_WINDOW(window), GTK_FILE_CHOOSER_ACTION_OPEN, GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL, GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT, NULL);

    /*Load Image*/

    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT)
    {
        char *path;
        path = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
        gtk_image_set_from_file(GTK_IMAGE(image), path);
        g_free(path);
    }

    gtk_widget_destroy(dialog);
}

void save_text(GtkWidget *window)
{
    /*Initialisation*/

    GtkWidget *dialog;

    /*Definition*/

    dialog = gtk_file_chooser_dialog_new("Save Text", GTK_WINDOW(window), GTK_FILE_CHOOSER_ACTION_SAVE, GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL, GTK_STOCK_SAVE, GTK_RESPONSE_ACCEPT, NULL);

    /*Save Text*/

    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT)
    {
        char *path;
        path = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
        //save_to_file(path);
        g_free(path);
    }

    gtk_widget_destroy(dialog);
}

void grayscale(void)
{
    gtk_main_quit();
}

void generate_text(GtkWidget *list[])
{
    /*Initialisation*/

    GtkWidget *window;
    GtkWidget *image;
    GtkWidget *text_label;
    GtkWidget *dialog;

    /*Definition*/

    window = list[0];
    image = list[1];
    text_label = list[2];
    dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_OK, "No image loaded, cannot generate text");

    /*Generate text*/

    if (gtk_image_get_storage_type(GTK_IMAGE(image)) == GTK_IMAGE_EMPTY)
    {
        if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_OK)
        {
            gtk_widget_destroy(dialog);
        }
    }
    else
    {
        gtk_label_set_label(GTK_LABEL(text_label), "Generated Text");
    }
}

int main(int argc, char **argv)
{

    /*Initialisation*/

    GtkWidget *main_window;
    GtkWidget *table;
    GtkWidget *load_button;
    GtkWidget *save_button;
    GtkWidget *grayscale_button;
    GtkWidget *image;
    GtkWidget *text_label;
    GtkWidget *text_button;
    GtkWidget *list[3];
    GtkWidget *frame_image;
    GtkWidget *frame_text;

    gtk_init(&argc, &argv);

    /*Main Window*/

    main_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(main_window), "OCR: Optical Character Recognition Program");
    gtk_window_set_position(GTK_WINDOW(main_window), GTK_WIN_POS_CENTER);
    gtk_window_maximize(GTK_WINDOW(main_window));

    /*Widget_list*/

    load_button = gtk_button_new_with_label("Load Image");
    save_button = gtk_button_new_with_label("Save Text");
    grayscale_button = gtk_button_new_with_label("Grayscale");
    image = gtk_image_new();
    text_button = gtk_button_new_with_label("Generate Text");
    text_label = gtk_label_new("Text from Image");
    list[0] = main_window;
    list[1] = image;
    list[2] = text_label;
    frame_image = gtk_frame_new(NULL);
    frame_text = gtk_frame_new(NULL);

    /*Table*/

    table = gtk_table_new(4, 30, FALSE);
    gtk_container_add(GTK_CONTAINER(main_window), table);

    gtk_table_attach_defaults(GTK_TABLE(table), load_button, 0, 1, 0, 1);
    gtk_table_attach_defaults(GTK_TABLE(table), text_button, 0, 1, 1, 2);
    gtk_table_attach_defaults(GTK_TABLE(table), save_button, 0, 1, 2, 3);
    gtk_table_attach_defaults(GTK_TABLE(table), grayscale_button, 0, 1, 3, 4);
    gtk_table_attach_defaults(GTK_TABLE(table), image, 1, 20, 0, 4);
    gtk_table_attach_defaults(GTK_TABLE(table), text_label, 20, 30, 0, 4);
    gtk_table_attach_defaults(GTK_TABLE(table), frame_image, 1, 20, 0, 4);
    gtk_table_attach_defaults(GTK_TABLE(table), frame_text, 20, 30, 0, 4);

    /*Callbacks*/

    g_signal_connect_swapped(G_OBJECT(load_button), "clicked", G_CALLBACK(load_image), list);
    g_signal_connect_swapped(G_OBJECT(save_button), "clicked", G_CALLBACK(save_text), NULL);
    g_signal_connect_swapped(G_OBJECT(grayscale_button), "clicked", G_CALLBACK(grayscale), NULL);
    g_signal_connect_swapped(G_OBJECT(text_button), "clicked", G_CALLBACK(generate_text), list); 

    /*Event Loop*/

    gtk_widget_show_all(main_window);
    g_signal_connect(G_OBJECT(main_window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_main();

    gtk_exit(EXIT_SUCCESS);
    return EXIT_SUCCESS;
}
