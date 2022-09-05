#!/usr/bin/env python3
# -*- coding: utf-8 -*-
#

# Importe a lib do GTK:
import gi
gi.require_version("Gtk","3.0")
from gi.repository import Gtk as gtk
from gi.repository import Gio as gio

import sys

class MacroKeyLinux(gtk.Window):

    def __init__(self):
        gtk.Window.__init__(self, title="MacroKeyBoard")
        #self.image.set_from_file('/home/bsilva/Videos/DRAWIO/promicro2.png')

        # Create Boxes. The space is between buttons
        self.box = gtk.Box(spacing=3, homogeneous=True)
        self.add(self.box)

        # Buttons
        self.test_button = gtk.Button(label="Test")
        self.test_button.connect("clicked", self.test_clicked)
        self.box.pack_start(self.test_button, True, True, 0)

        self.test_button1 = gtk.Button(label="Test1")
        self.test_button1.connect("clicked", self.test_clicked1)
        self.box.pack_start(self.test_button1, True, True, 0)

    def test_clicked(self, widge):
        print('You clicked test!')

    def test_clicked1(self, widge):
        print('You clicked test1!')

window = MacroKeyLinux()
window.connect("delete-event", gtk.main_quit)
window.show_all()
gtk.main()




# Links:
# https://python-gtk-3-tutorial.readthedocs.io/en/latest/layout.html
# https://lazka.github.io/pgi-docs/Gtk-3.0/classes/Box.html
# https://youtu.be/JeSBCfm3BqM
# https://docs.gtk.org/gtk3/class.Box.html
