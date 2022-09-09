#!/usr/bin/env python3
# -*- coding: utf-8 -*-
#

import gi, os, subprocess, sys, signal
gi.require_version("Gtk", "3.0")
from gi.repository import Gtk, Gdk


class Handler(object):

    def __init__(self):
        #self.configuration_file = os.getenv('HOME') + '/.config/macrokeyboard_python/config'
        #self.css_file = os.getenv('HOME') + '/.config/macrokeyboard_python/settings.css'
        self.css_file = os.getenv('HOME') + '/.config/macrokeyboard_python/settings.css'
        self.configuration_file = os.getenv('HOME') + '/.config/macrokeyboard_python/config'

        if not os.path.exists(self.configuration_file):
            self.error('Arquivo de configuracao nao encontrado em: ' + '\n' + self.configuration_file)
        
        elif not os.path.exists(self.css_file):
            self.error('Arquivo de configuracao nao encontrado em: ' + '\n' + self.css_file)

        self.Stack: Gtk.Stack = builder.get_object('stack_inter')
        #self.stack = Gtk.Stack()
        #self.stack = builder.get_object("stack")

        self.build_menu()

    def error(self, message):
        window = Gtk.Window(title="Error Information")
        window.set_default_size(470, 150)
        window.set_position(Gtk.WindowPosition.CENTER)
        window.connect("destroy", Gtk.main_quit)

        label = Gtk.Label()
        label.set_text(message)
        label.set_line_wrap(wrap=True) # Quebra de linha
        #label.set_selectable(setting=True) # Permite selecionar o texto

        window.add(label)
        window.show_all()
        Gtk.main()
        #print('Erro -', message)
        sys.exit(12)

    def icons(self):
        css_provider = Gtk.CssProvider()
        css_provider.load_from_path(self.css_file)
        screen = Gdk.Screen()
        style_context = Gtk.StyleContext()
        style_context.add_provider_for_screen(screen.get_default(),
                                              css_provider,
                                              Gtk.STYLE_PROVIDER_PRIORITY_APPLICATION)

    def build_menu(self):
        self.icons()

        if not os.path.exists(self.configuration_file):
            self.error('Arquivo de configuracao nao encontrado em: ' + '\n' + self.configuration_file)
        
        elif not os.path.exists(self.css_file):
            self.error('Arquivo de configuracao nao encontrado em: ' + '\n' + self.css_file)

        config = open(self.configuration_file, 'r')

        try:
            counter = 0
            for line_file in config.readlines():
                counter = counter+1
                line_file = line_file.split()

                if len(line_file) < 1:
                    continue

                # Remove comment:
                if line_file[0] == '#':
                    continue
                
                old_name = line_file[0].lower()
                exec_level = line_file[1].lower()
                new_name = line_file[2]
                command = line_file[3:]

                self.build_button_by_configuration_file(old_name, new_name, exec_level, command)
        finally:
            config.close()

    def build_button_by_configuration_file(self, old_name, new_name, exec_level, command):
        button_builder = builder.get_object(old_name)
        button_builder.set_label('\n\n\n\n\n'+new_name)

        if exec_level == 'systemcall':
            button_builder.connect('clicked', self.on_clicked_systemcall, command)

        elif exec_level == 'write':
            button_builder.connect('clicked', self.on_clicked_write, command)
        
        elif exec_level == 'hotkey':
            button_builder.connect('clicked', self.on_clicked_hotkey, command)

    def on_clicked_systemcall(self, widget, command):
        subprocess.run(command)

    # Under development:
    def on_clicked_write(self, widget, command):
        command

    # Under development:
    def on_clicked_hotkey(self, widget, command):
        pass

    def on_main_window_destroy(self, window):
        Gtk.main_quit()

    def on_profile1(self, window):
        self.Stack.set_visible_child_name("profile1")

    def on_profile2(self, widget):
        self.Stack.set_visible_child_name("profile2")

    def on_profile3(self, window):
        self.Stack.set_visible_child_name("profile3")

    def on_profile4(self, window):
        self.Stack.set_visible_child_name("profile4")

def error(message):
    window = Gtk.Window(title="Error Information")
    window.set_default_size(470, 150)
    window.set_position(Gtk.WindowPosition.CENTER)
    window.connect("destroy", Gtk.main_quit)

    label = Gtk.Label()
    label.set_text(message)
    label.set_line_wrap(wrap=True) # Quebra de linha
    #label.set_selectable(setting=True) # Permite selecionar o texto

    window.add(label)
    window.show_all()
    Gtk.main()
    #print('Erro -', message)
    sys.exit(12)

if __name__ == "__main__":
    # Isso fará com que o script reaja normalmente ao Ctrl + C no terminal.
    signal.signal(signal.SIGINT, signal.SIG_DFL)


    interface_layout_file = os.getenv('HOME') + '/.config/macrokeyboard_python/layout.grade'
    if not os.path.exists(interface_layout_file):
        error('Arquivo de configuracao nao encontrado em: ' + '\n' + interface_layout_file)
        
    builder = Gtk.Builder()
    #builder.add_from_file("layout_macrokeyboard.glade")
    builder.add_from_file("layout_macrokeyboard_v2.glade")
    builder.connect_signals(Handler())

    window = builder.get_object("main_window")
    #window.set_title('MacroKeyBoard Python')
    window.show_all()

    Gtk.main()
