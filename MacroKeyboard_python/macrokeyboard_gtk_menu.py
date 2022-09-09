#!/usr/bin/env python3
# -*- coding: utf-8 -*-
#

# Importe a lib do Gtk:
	

import gi, subprocess, os, sys

gi.require_version("Gtk", "3.0")
from gi.repository import Gtk as gtk


class MacroKeyLinux(gtk.Window):

    def __init__(self):
        self.configuration_file = os.getenv('HOME') + '/.config/macrokeyboard_python/config'

        if not os.path.exists(self.configuration_file):
            self.error('Arquivo de configuracao nao encontrado em: ' + '\n' + self.configuration_file)

        gtk.Window.__init__(self, title="MacroKeyBoard")
        self.set_border_width(10)
        self.set_default_size (800, 200)
        self.set_position(gtk.WindowPosition.CENTER)

        self.box = gtk.Box(spacing=0, homogeneous=True, orientation=gtk.Orientation.HORIZONTAL)
        self.add(self.box)
        self.build_menu()


    def error(self, message):
        window = gtk.Window(title="Error Information")
        window.set_default_size(470, 150)
        window.connect("destroy", gtk.main_quit)

        label = gtk.Label()
        label.set_text(message)
        label.set_line_wrap(wrap=True) # Quebra de linha
        #label.set_selectable(setting=True) # Permite selecionar o texto

        window.add(label)
        window.show_all()
        gtk.main()
        #print('Erro -', message)
        sys.exit(12)


    def build_menu(self):
        config = open(self.configuration_file, 'r')
        try:
            counter = 0
            
            for line_file in config.readlines():
                counter = counter+1
                line_file = line_file.split()

                if len(line_file) < 1:
                    continue




        # Buttons
        self.test_button = gtk.Button(label="Test")
        self.test_button.set_halign(gtk.Align.FILL)
        self.test_button.set_valign(gtk.Align.START)
        self.test_button.connect("clicked", self.test_clicked)
        self.box.pack_start(self.test_button, True, True, 0)

        self.test_button1 = gtk.Button(label="Test1")
        self.test_button1.set_halign(gtk.Align.FILL)
        self.test_button1.set_valign(gtk.Align.START)
        self.test_button1.connect("clicked", self.test_clicked1)
        self.box.pack_start(self.test_button1, True, True, 0)

    def test_clicked(self, widge):
        print('You clicked test!')

    def test_clicked1(self, widge):
        print('You clicked test1!')

win = MacroKeyLinux()
win.connect("destroy", gtk.main_quit)
win.show_all()
gtk.main()



