#include <gtk/gtk.h>

// 按钮点击回调函数
static void on_button_clicked(GtkWidget *widget, gpointer data) {
    g_print("Button %s clicked\n", (char *) data);
}

int main(int argc, char *argv[]) {
    GtkBuilder *builder;
    GtkWidget *window;
    GtkWidget *button1, *button2, *button3;

    // 初始化 GTK
    gtk_init(&argc, &argv);

    // 加载 XML 文件
    builder = gtk_builder_new_from_file("../layout.xml");

    // 获取窗口对象
    window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // 获取按钮对象并连接信号
    button1 = GTK_WIDGET(gtk_builder_get_object(builder, "button1"));
    g_signal_connect(button1, "clicked", G_CALLBACK(on_button_clicked), "1");

    button2 = GTK_WIDGET(gtk_builder_get_object(builder, "button2"));
    g_signal_connect(button2, "clicked", G_CALLBACK(on_button_clicked), "2");

    button3 = GTK_WIDGET(gtk_builder_get_object(builder, "button3"));
    g_signal_connect(button3, "clicked", G_CALLBACK(on_button_clicked), "3");

    // 显示窗口
    gtk_widget_show_all(window);

    // 主循环
    gtk_main();

    // 释放资源
    g_object_unref(builder);

    return 0;
}
