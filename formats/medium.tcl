# IR toolkit for tcl/tk
# (c) Index Data 1995
# See the file LICENSE for details.
# Sebastian Hammer, Adam Dickmeiss
#
# $Log: medium.tcl,v $
# Revision 1.4  1995-06-14 12:16:42  adam
# Minor presentation format changes.
#
# Revision 1.3  1995/06/13  14:39:06  adam
# Fix: if {$var != ""} doesn't work if var is a large numerical!
# Highlight when line format is used.
#
# Revision 1.2  1995/06/12  15:18:10  adam
# Work on presentation formats. These are used in the main window as well
# as popup windows.
#
#

proc display-medium {sno no w hflag} {
    if {$hflag} {
        insertWithTags $w "\n$no\n" marc-data
    } else {
        $w delete 0.0 end
    }
    set i [z39.$sno getMarc $no field 245 * a]
    if {"x$i" != "x"} {
        insertWithTags $w "Title:      " marc-tag
        insertWithTags $w [string trimright [lindex $i 0] /] marc-data
        set i [z39.$sno getMarc $no field 245 * b]
        if {"x$i" != "x"} {
            insertWithTags $w [string trimright [lindex $i 0] /] marc-data
        }
        $w insert end "\n"
    }
    set i [z39.$sno getMarc $no field 700 * a]
    if {"x$i" == "x"} {
        set i [z39.$sno getMarc $no field 100 * a]
    }
    if {"x$i" != "x"} {
        if {[llength $i] > 1} {
            insertWithTags $w "Authors:    " marc-tag
        } else {
            insertWithTags $w "Author:     " marc-tag
        }
        foreach x $i {
            insertWithTags $w $x marc-data
        }
        $w insert end "\n"
    }
    set i [z39.$sno getMarc $no field 110 * *]
    if {"x$i" != "x"} {
        insertWithTags $w "Co-Author:  " marc-tag
        foreach x $i {
            insertWithTags $w $x marc-data
        }
        $w insert end "\n"
    }

    set i [z39.$sno getMarc $no field 650 * *]
    if {"x$i" != "x"} {
        set n 0
        insertWithTags $w "Keywords:   " marc-tag
        foreach x $i {
            if {$n > 0} {
                $w insert end ", "
            }
            insertWithTags $w $x marc-data
            incr n
        }
        $w insert end "\n"
    }
    set i [concat [z39.$sno getMarc $no field 260 * a] \
            [z39.$sno getMarc $no field 260 * b]]
    if {"x$i" != "x"} {
        insertWithTags $w "Publisher:  " marc-tag
        foreach x $i {
            insertWithTags $w $x marc-data
        }
        $w insert end "\n"
    }
    set i [z39.$sno getMarc $no field 020 * a]
    if {"x$i" != "x"} {
        insertWithTags $w "ISBN:       " marc-tag
        foreach x $i {
            insertWithTags $w $x marc-data
        }
        $w insert end "\n"
    }
    set i [z39.$sno getMarc $no field 022 * a]
    if {"x$i" != "x"} {
        insertWithTags $w "ISSN:       " marc-tag
        foreach x $i {
            insertWithTags $w $x marc-data
        }
        $w insert end "\n"
    }
    set i [z39.$sno getMarc $no field 030 * a]
    if {"x$i" != "x"} {
        insertWithTags $w "CODEN:      " marc-tag
        foreach x $i {
            insertWithTags $w $x marc-data
        }
        $w insert end "\n"
    }
    set i [z39.$sno getMarc $no field 015 * a]
    if {"x$i" != "x"} {
        insertWithTags $w "Ctl number: " marc-tag
        foreach x $i {
            insertWithTags $w $x marc-data
        }
        $w insert end "\n"
    }
    set i [z39.$sno getMarc $no field 010 * a]
    if {"x$i" != "x"} {
        insertWithTags $w "LC number:  " marc-tag
        foreach x $i {
            insertWithTags $w $x marc-data
        }
        $w insert end "\n"
    }
}