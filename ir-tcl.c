/*
 * IR toolkit for tcl/tk
 * (c) Index Data 1995
 * See the file LICENSE for details.
 * Sebastian Hammer, Adam Dickmeiss
 *
 * $Log: ir-tcl.c,v $
 * Revision 1.62  1995-10-18 17:20:33  adam
 * Work on target setup in client.tcl.
 *
 * Revision 1.61  1995/10/18  16:42:42  adam
 * New settings: smallSetElementSetNames and mediumSetElementSetNames.
 *
 * Revision 1.60  1995/10/18  15:43:31  adam
 * In search: mediumSetElementSetNames and smallSetElementSetNames are
 * set to elementSetNames.
 *
 * Revision 1.59  1995/10/17  12:18:58  adam
 * Bug fix: when target connection closed, the connection was not
 * properly reestablished.
 *
 * Revision 1.58  1995/10/16  17:00:55  adam
 * New setting: elementSetNames.
 * Various client improvements. Medium presentation format looks better.
 *
 * Revision 1.57  1995/09/21  13:11:51  adam
 * Support of dynamic loading.
 * Test script uses load command if necessary.
 *
 * Revision 1.56  1995/08/29  15:30:14  adam
 * Work on GRS records.
 *
 * Revision 1.55  1995/08/28  09:43:25  adam
 * Minor changes. configure only searches for yaz beta 3 and versions after
 * that.
 *
 * Revision 1.54  1995/08/24  12:25:16  adam
 * Modified to work with yaz 1.0b3.
 *
 * Revision 1.53  1995/08/04  12:49:26  adam
 * Bug fix: reading uninitialized variable p.
 *
 * Revision 1.52  1995/08/04  11:32:38  adam
 * More work on output queue. Memory related routines moved
 * to mem.c
 *
 * Revision 1.51  1995/08/03  13:22:54  adam
 * Request queue.
 *
 * Revision 1.50  1995/07/20  08:09:49  adam
 * client.tcl: Targets removed from hotTargets list when targets
 *  are removed/modified.
 * ir-tcl.c: More work on triggerResourceControl.
 *
 * Revision 1.49  1995/06/30  12:39:21  adam
 * Bug fix: loadFile didn't set record type.
 * The MARC routines are a little less strict in the interpretation.
 * Script display.tcl replaces the old marc.tcl.
 * New interactive script: shell.tcl.
 *
 * Revision 1.48  1995/06/27  19:03:50  adam
 * Bug fix in do_present in ir-tcl.c: p->set_child member weren't set.
 * nextResultSetPosition used instead of setOffset.
 *
 * Revision 1.47  1995/06/25  10:25:04  adam
 * Working on triggerResourceControl. Description of compile/install
 * procedure moved to ir-tcl.sgml.
 *
 * Revision 1.46  1995/06/22  13:15:06  adam
 * Feature: SUTRS. Setting getSutrs implemented.
 * Work on display formats.
 * Preferred record syntax can be set by the user.
 *
 * Revision 1.45  1995/06/20  08:07:30  adam
 * New setting: failInfo.
 * Working on better cancel mechanism.
 *
 * Revision 1.44  1995/06/19  17:01:20  adam
 * Minor changes.
 *
 * Revision 1.43  1995/06/19  13:06:08  adam
 * New define: IR_TCL_VERSION.
 *
 * Revision 1.42  1995/06/19  08:08:52  adam
 * client.tcl: hotTargets now contain both database and target name.
 * ir-tcl.c: setting protocol edited. Errors in callbacks are logged
 * by logf(LOG_WARN, ...) calls.
 *
 * Revision 1.41  1995/06/16  12:28:16  adam
 * Implemented preferredRecordSyntax.
 * Minor changes in diagnostic handling.
 * Record list deleted when connection closes.
 *
 * Revision 1.40  1995/06/14  13:37:18  adam
 * Setting recordType implemented.
 * Setting implementationVersion implemented.
 * Settings implementationId / implementationName edited.
 *
 * Revision 1.39  1995/06/08  10:26:32  adam
 * Bug fix in ir_strdup.
 *
 * Revision 1.38  1995/06/01  16:36:47  adam
 * About buttons. Minor bug fixes.
 *
 * Revision 1.37  1995/06/01  07:31:20  adam
 * Rename of many typedefs -> IrTcl_...
 *
 * Revision 1.36  1995/05/31  13:09:59  adam
 * Client searches/presents may be interrupted.
 * New moving book-logo.
 *
 * Revision 1.35  1995/05/31  08:36:33  adam
 * Bug fix in client.tcl: didn't save options on clientrc.tcl.
 * New method: referenceId. More work on scan.
 *
 * Revision 1.34  1995/05/29  10:33:42  adam
 * README and rename of startup script.
 *
 * Revision 1.33  1995/05/29  09:15:11  quinn
 * Changed CS_SR to PROTO_SR, etc.
 *
 * Revision 1.32  1995/05/29  08:44:16  adam
 * Work on delete of objects.
 *
 * Revision 1.31  1995/05/26  11:44:10  adam
 * Bugs fixed. More work on MARC utilities and queries. Test
 * client is up-to-date again.
 *
 * Revision 1.30  1995/05/26  08:54:11  adam
 * New MARC utilities. Uses prefix query.
 *
 * Revision 1.29  1995/05/24  14:10:22  adam
 * Work on idAuthentication, protocolVersion and options.
 *
 * Revision 1.28  1995/05/23  15:34:48  adam
 * Many new settings, userInformationField, smallSetUpperBound, etc.
 * A number of settings are inherited when ir-set is executed.
 * This version is incompatible with the graphical test client (client.tcl).
 *
 * Revision 1.27  1995/05/11  15:34:47  adam
 * Scan request changed a bit. This version works with RLG.
 *
 * Revision 1.26  1995/04/18  16:11:51  adam
 * First version of graphical Scan. Some work on query-by-form.
 *
 * Revision 1.25  1995/04/17  09:37:17  adam
 * Further development of scan.
 *
 * Revision 1.24  1995/04/11  14:16:42  adam
 * Further work on scan. Response works. Entries aren't saved yet.
 *
 * Revision 1.23  1995/04/10  10:50:27  adam
 * Result-set name defaults to suffix of ir-set name.
 * Started working on scan. Not finished at this point.
 *
 * Revision 1.22  1995/03/31  10:43:03  adam
 * More robust when getting bad MARC records.
 *
 * Revision 1.21  1995/03/31  08:56:37  adam
 * New button "Search".
 *
 * Revision 1.20  1995/03/29  16:07:09  adam
 * Bug fix: Didn't use setName in present request.
 *
 * Revision 1.19  1995/03/28  12:45:23  adam
 * New ir method failback: called on disconnect/protocol error.
 * New ir set/get method: protocol: SR / Z3950.
 * Simple popup and disconnect when failback is invoked.
 *
 * Revision 1.18  1995/03/21  15:50:12  adam
 * Minor changes.
 *
 * Revision 1.17  1995/03/21  13:41:03  adam
 * Comstack cs_create not used too often. Non-blocking connect.
 *
 * Revision 1.16  1995/03/21  08:26:06  adam
 * New method, setName, to specify the result set name (other than Default).
 * New method, responseStatus, which returns diagnostic info, if any, after
 * present response / search response.
 *
 * Revision 1.15  1995/03/20  15:24:07  adam
 * Diagnostic records saved on searchResponse.
 *
 * Revision 1.14  1995/03/20  08:53:22  adam
 * Event loop in tclmain.c rewritten. New method searchStatus.
 *
 * Revision 1.13  1995/03/17  18:26:17  adam
 * Non-blocking i/o used now. Database names popup as cascade items.
 *
 * Revision 1.12  1995/03/17  15:45:00  adam
 * Improved target/database setup.
 *
 * Revision 1.11  1995/03/16  17:54:03  adam
 * Minor changes really.
 *
 * Revision 1.10  1995/03/15  16:14:50  adam
 * Blocking arg in cs_create changed.
 *
 * Revision 1.9  1995/03/15  13:59:24  adam
 * Minor changes.
 *
 * Revision 1.8  1995/03/15  08:25:16  adam
 * New method presentStatus to check for error on present. Misc. cleanup
 * of IrTcl_RecordList manipulations. Full MARC record presentation in
 * search.tcl.
 *
 * Revision 1.7  1995/03/14  17:32:29  adam
 * Presentation of full Marc record in popup window.
 *
 * Revision 1.6  1995/03/12  19:31:55  adam
 * Pattern matching implemented when retrieving MARC records. More
 * diagnostic functions.
 *
 * Revision 1.5  1995/03/10  18:00:15  adam
 * Actual presentation in line-by-line format. RPN query support.
 *
 * Revision 1.4  1995/03/09  16:15:08  adam
 * First presentRequest attempts. Hot-target list.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <assert.h>

#define CS_BLOCK 0

#include "ir-tclp.h"

typedef struct {
    int type;
    char *name;
    int (*method) (void *obj, Tcl_Interp *interp, int argc, char **argv);
} IrTcl_Method;

typedef struct {
    void *obj;
    IrTcl_Method *tab;
} IrTcl_Methods;

static void ir_deleteDiags (IrTcl_Diagnostic **dst_list, int *dst_num);
static int do_disconnect (void *obj, Tcl_Interp *interp, 
                          int argc, char **argv);

static IrTcl_RecordList *new_IR_record (IrTcl_SetObj *setobj, 
                                        int no, int which)
{
    IrTcl_RecordList *rl;

    for (rl = setobj->record_list; rl; rl = rl->next)
    {
        if (no == rl->no)
        {
            switch (rl->which)
            {
            case Z_NamePlusRecord_databaseRecord:
	        free (rl->u.dbrec.buf);
		rl->u.dbrec.buf = NULL;
                break;
            case Z_NamePlusRecord_surrogateDiagnostic:
                ir_deleteDiags (&rl->u.surrogateDiagnostics.list,
                                &rl->u.surrogateDiagnostics.num);
                break;
            }
            break;
        }
    }
    if (!rl)
    {
        rl = ir_tcl_malloc (sizeof(*rl));
        rl->next = setobj->record_list;
        rl->no = no;
        setobj->record_list = rl;
    }
    rl->which = which;
    return rl;
}

static struct {
    enum oid_value value;
    const char *name;
} IrTcl_recordSyntaxTab[] = { 
{ VAL_UNIMARC,    "UNIMARC" },
{ VAL_INTERMARC,  "INTERMARC" },
{ VAL_CCF,        "CCF" },
{ VAL_USMARC,     "USMARC" },
{ VAL_UKMARC,     "UKMARC" },
{ VAL_NORMARC,    "NORMARC" },
{ VAL_LIBRISMARC, "LIBRISMARC" },
{ VAL_DANMARC,    "DANMARC" },
{ VAL_FINMARC,    "FINMARC" },
{ VAL_MAB,        "MAB" },
{ VAL_CANMARC,    "CANMARC" },
{ VAL_SBN,        "SBN" },
{ VAL_PICAMARC,   "PICAMARC" },
{ VAL_AUSMARC,    "AUSMARC" },
{ VAL_IBERMARC,   "IBERMARC" },
{ VAL_SUTRS,      "SUTRS" },
{ VAL_GRS1,       "GRS1" },
{ 0, NULL }
};

/* 
 * IrTcl_eval
 */
int IrTcl_eval (Tcl_Interp *interp, const char *command)
{
    char *tmp = ir_tcl_malloc (strlen(command)+1);
    int r;

    strcpy (tmp, command);
    r = Tcl_Eval (interp, tmp);
    if (r == TCL_ERROR)
        logf (LOG_WARN, "Tcl error in line %d: %s", interp->errorLine, 
              interp->result);
    Tcl_FreeResult (interp);
    free (tmp);
    return r;
}

/*
 * IrTcl_getRecordSyntaxStr: Return record syntax name of object id
 */
static const char *IrTcl_getRecordSyntaxStr (enum oid_value value)
{
    int i;
    for (i = 0; IrTcl_recordSyntaxTab[i].name; i++) 
        if (IrTcl_recordSyntaxTab[i].value == value)
            return IrTcl_recordSyntaxTab[i].name;
    return "USMARC";
}

/*
 * IrTcl_getRecordSyntaxVal: Return record syntax value of string
 */
static enum oid_value IrTcl_getRecordSyntaxVal (const char *name)
{
    int i;
    for (i = 0; IrTcl_recordSyntaxTab[i].name; i++) 
        if (!strcmp (IrTcl_recordSyntaxTab[i].name, name))
            return IrTcl_recordSyntaxTab[i].value;
    return 0;
}

static IrTcl_RecordList *find_IR_record (IrTcl_SetObj *setobj, int no)
{
    IrTcl_RecordList *rl;

    for (rl = setobj->record_list; rl; rl = rl->next)
        if (no == rl->no)
            return rl;
    return NULL;
}

static void delete_IR_records (IrTcl_SetObj *setobj)
{
    IrTcl_RecordList *rl, *rl1;

    for (rl = setobj->record_list; rl; rl = rl1)
    {
        switch (rl->which)
        {
        case Z_NamePlusRecord_databaseRecord:
	    free (rl->u.dbrec.buf);
            break;
        case Z_NamePlusRecord_surrogateDiagnostic:
            ir_deleteDiags (&rl->u.surrogateDiagnostics.list,
                            &rl->u.surrogateDiagnostics.num);
            break;
	}
	rl1 = rl->next;
	free (rl);
    }
    setobj->record_list = NULL;
}

/*
 * get_set_int: Set/get integer value
 */
static int get_set_int (int *val, Tcl_Interp *interp, int argc, char **argv)
{
    char buf[20];
    
    if (argc == 3)
    {
        if (Tcl_GetInt (interp, argv[2], val)==TCL_ERROR)
            return TCL_ERROR;
    }
    sprintf (buf, "%d", *val);
    Tcl_AppendResult (interp, buf, NULL);
    return TCL_OK;
}

/*
 * ir_method: Search for method in table and invoke method handler
 */
int ir_method (Tcl_Interp *interp, int argc, char **argv, IrTcl_Methods *tab)
{
    IrTcl_Methods *tab_i = tab;
    IrTcl_Method *t;

    for (tab_i = tab; tab_i->tab; tab_i++)
        for (t = tab_i->tab; t->name; t++)
	    if (argc <= 0)
	    {
	        if ((*t->method)(tab_i->obj, interp, argc, argv) == TCL_ERROR)
		    return TCL_ERROR;
            }
	    else
                if (!strcmp (t->name, argv[1]))
                    return (*t->method)(tab_i->obj, interp, argc, argv);

    if (argc <= 0)
        return TCL_OK;
    Tcl_AppendResult (interp, "Bad method: ", argv[1], 
                      ". Possible methods:", NULL);
    for (tab_i = tab; tab_i->tab; tab_i++)
        for (t = tab_i->tab; t->name; t++)
            Tcl_AppendResult (interp, " ", t->name, NULL);
    return TCL_ERROR;
}

/*
 * ir_method_r: Get status for all readable elements
 */
int ir_method_r (void *obj, Tcl_Interp *interp, int argc, char **argv,
                 IrTcl_Method *tab)
{
    char *argv_n[3];
    int argc_n;

    argv_n[0] = argv[0];
    argc_n = 2;
    for (; tab->name; tab++)
        if (tab->type)
        {
            argv_n[1] = tab->name;
            Tcl_AppendResult (interp, "{", NULL);
            (*tab->method)(obj, interp, argc_n, argv_n);
            Tcl_AppendResult (interp, "} ", NULL);
        }
    return TCL_OK;
}

/*
 *  ir_named_bits: get/set named bits
 */
int ir_named_bits (struct ir_named_entry *tab, Odr_bitmask *ob,
                   Tcl_Interp *interp, int argc, char **argv)
{
    struct ir_named_entry *ti;
    if (argc > 0)
    {
        int no;
        ODR_MASK_ZERO (ob);
        for (no = 0; no < argc; no++)
        {
            for (ti = tab; ti->name; ti++)
                if (!strcmp (argv[no], ti->name))
                {
                    ODR_MASK_SET (ob, ti->pos);
                    break;
                }
            if (!ti->name)
            {
                Tcl_AppendResult (interp, "Bad bit mask: ", argv[no], NULL);
                return TCL_ERROR;
            }
        }
        return TCL_OK;
    }
    for (ti = tab; ti->name; ti++)
        if (ODR_MASK_GET (ob, ti->pos))
            Tcl_AppendElement (interp, ti->name);
    return TCL_OK;
}

static void set_referenceId (ODR o, Z_ReferenceId **dst, const char *src)
{
    if (!src || !*src)
        *dst = NULL;
    else
    {
        *dst = odr_malloc (o, sizeof(**dst));
	(*dst)->size = (*dst)->len = strlen(src);
	(*dst)->buf = odr_malloc (o, (*dst)->len);
	memcpy ((*dst)->buf, src, (*dst)->len);
    }
}

static void get_referenceId (char **dst, Z_ReferenceId *src)
{
    free (*dst);
    if (!src)
    {
        *dst = NULL;
	return;
    }
    *dst = ir_tcl_malloc (src->len+1);
    memcpy (*dst, src->buf, src->len);
    (*dst)[src->len] = '\0';
}

/* ------------------------------------------------------- */

/*
 * do_init_request: init method on IR object
 */
static int do_init_request (void *obj, Tcl_Interp *interp,
                            int argc, char **argv)
{
    Z_APDU *apdu;
    IrTcl_Obj *p = obj;
    Z_InitRequest *req;

    if (argc <= 0)
        return TCL_OK;
    if (!p->cs_link)
    {
        interp->result = "init: not connected";
        return TCL_ERROR;
    }
    apdu = zget_APDU (p->odr_out, Z_APDU_initRequest);
    req = apdu->u.initRequest;

    set_referenceId (p->odr_out, &req->referenceId, p->set_inher.referenceId);
    req->options = &p->options;
    req->protocolVersion = &p->protocolVersion;
    req->preferredMessageSize = &p->preferredMessageSize;
    req->maximumRecordSize = &p->maximumRecordSize;

    if (p->idAuthenticationGroupId)
    {
        Z_IdPass *pass = odr_malloc (p->odr_out, sizeof(*pass));
        Z_IdAuthentication *auth = odr_malloc (p->odr_out, sizeof(*auth));

        auth->which = Z_IdAuthentication_idPass;
        auth->u.idPass = pass;
        if (p->idAuthenticationGroupId && *p->idAuthenticationGroupId)
            pass->groupId = p->idAuthenticationGroupId;
        else
            pass->groupId = NULL;
        if (p->idAuthenticationUserId && *p->idAuthenticationUserId)
            pass->userId = p->idAuthenticationUserId;
        else
            pass->userId = NULL;
        if (p->idAuthenticationPassword && *p->idAuthenticationPassword)
            pass->password = p->idAuthenticationPassword;
        else
            pass->password = NULL;
        req->idAuthentication = auth;
    }
    else if (!p->idAuthenticationOpen || !*p->idAuthenticationOpen)
        req->idAuthentication = NULL;
    else
    {
        Z_IdAuthentication *auth = odr_malloc (p->odr_out, sizeof(*auth));

        auth->which = Z_IdAuthentication_open;
        auth->u.open = p->idAuthenticationOpen;
        req->idAuthentication = auth;
    }
    req->implementationId = p->implementationId;
    req->implementationName = p->implementationName;
    req->implementationVersion = p->implementationVersion;
    req->userInformationField = 0;

    return ir_tcl_send_APDU (interp, p, apdu, "init", argv[0]);
}

/*
 * do_protocolVersion: Set protocol Version
 */
static int do_protocolVersion (void *obj, Tcl_Interp *interp,
                               int argc, char **argv)
{
    int version, i;
    char buf[10];
    IrTcl_Obj *p = obj;

    if (argc <= 0)
    {
        ODR_MASK_ZERO (&p->protocolVersion);
	ODR_MASK_SET (&p->protocolVersion, 0);
	ODR_MASK_SET (&p->protocolVersion, 1);
        return TCL_OK;
    }
    if (argc == 3)
    {
        if (Tcl_GetInt (interp, argv[2], &version)==TCL_ERROR)
            return TCL_ERROR;
        ODR_MASK_ZERO (&p->protocolVersion);
        for (i = 0; i<version; i++)
            ODR_MASK_SET (&p->protocolVersion, i);
    }
    for (i = 4; --i >= 0; )
        if (ODR_MASK_GET (&p->protocolVersion, i))
            break;
    sprintf (buf, "%d", i+1);
    interp->result = buf;
    return TCL_OK;
}

/*
 * do_options: Set options
 */
static int do_options (void *obj, Tcl_Interp *interp,
                       int argc, char **argv)
{
    static struct ir_named_entry options_tab[] = {
    { "search", 0 },
    { "present", 1 },
    { "delSet", 2 },
    { "resourceReport", 3 },
    { "triggerResourceCtrl", 4},
    { "resourceCtrl", 5},
    { "accessCtrl", 6},
    { "scan", 7},
    { "sort", 8},
    { "extendedServices", 10},
    { "level-1Segmentation", 11},
    { "level-2Segmentation", 12},
    { "concurrentOperations", 13},
    { "namedResultSets", 14},
    { NULL, 0}
    };
    IrTcl_Obj *p = obj;

    if (argc <= 0)
    {
        ODR_MASK_ZERO (&p->options);
	ODR_MASK_SET (&p->options, 0);
	ODR_MASK_SET (&p->options, 1);
        ODR_MASK_SET (&p->options, 4);
	ODR_MASK_SET (&p->options, 7);
	ODR_MASK_SET (&p->options, 14);
	return TCL_OK;
    }
    return ir_named_bits (options_tab, &p->options, interp, argc-2, argv+2);
}

/*
 * do_failInfo: Get fail information
 */
static int do_failInfo (void *obj, Tcl_Interp *interp, int argc, char **argv)
{
    char buf[16], *cp;
    IrTcl_Obj *p = obj;

    if (argc <= 0)
    {
        p->failInfo = 0;
	return TCL_OK;
    }
    sprintf (buf, "%d", p->failInfo);
    switch (p->failInfo)
    {
    case 0:
        cp = "ok";
        break;
    case IR_TCL_FAIL_CONNECT:
        cp = "connect failed";
        break;
    case IR_TCL_FAIL_READ:
        cp = "connection closed";
        break;
    case IR_TCL_FAIL_WRITE:
        cp = "connection closed";
        break;
    case IR_TCL_FAIL_IN_APDU:
        cp = "failed to decode incoming APDU";
        break;
    case IR_TCL_FAIL_UNKNOWN_APDU:
        cp = "unknown APDU";
        break;
    default:
        cp = "";
    } 
    Tcl_AppendElement (interp, buf);
    Tcl_AppendElement (interp, cp);
    return TCL_OK;
}

/*
 * do_preferredMessageSize: Set/get preferred message size
 */
static int do_preferredMessageSize (void *obj, Tcl_Interp *interp,
                                    int argc, char **argv)
{
    IrTcl_Obj *p = obj;

    if (argc <= 0)
    {
        p->preferredMessageSize = 30000;
	return TCL_OK;
    }
    return get_set_int (&p->preferredMessageSize, interp, argc, argv);
}

/*
 * do_maximumRecordSize: Set/get maximum record size
 */
static int do_maximumRecordSize (void *obj, Tcl_Interp *interp,
                                 int argc, char **argv)
{
    IrTcl_Obj *p = obj;

    if (argc <= 0)
    {
        p->maximumRecordSize = 30000;
	return TCL_OK;
    }
    return get_set_int (&p->maximumRecordSize, interp, argc, argv);
}

/*
 * do_initResult: Get init result
 */
static int do_initResult (void *obj, Tcl_Interp *interp,
                          int argc, char **argv)
{
    IrTcl_Obj *p = obj;
   
    if (argc <= 0)
        return TCL_OK;
    return get_set_int (&p->initResult, interp, argc, argv);
}


/*
 * do_implementationName: Set/get Implementation Name.
 */
static int do_implementationName (void *obj, Tcl_Interp *interp,
                                    int argc, char **argv)
{
    IrTcl_Obj *p = obj;

    if (argc == 0)
        return ir_tcl_strdup (interp, &p->implementationName,
                          "Index Data/IrTcl on YAZ");
    else if (argc == -1)
        return ir_tcl_strdel (interp, &p->implementationName);
    if (argc == 3)
    {
        free (p->implementationName);
        if (ir_tcl_strdup (interp, &p->implementationName, argv[2])
            == TCL_ERROR)
            return TCL_ERROR;
    }
    Tcl_AppendResult (interp, p->implementationName, (char*) NULL);
    return TCL_OK;
}

/*
 * do_implementationId: Get Implementation Id.
 */
static int do_implementationId (void *obj, Tcl_Interp *interp,
                                int argc, char **argv)
{
    IrTcl_Obj *p = obj;

    if (argc == 0)
        return ir_tcl_strdup (interp, &p->implementationId, "YAZ (id=81)");
    else if (argc == -1)
        return ir_tcl_strdel (interp, &p->implementationId);
    Tcl_AppendResult (interp, p->implementationId, (char*) NULL);
    return TCL_OK;
}

/*
 * do_implementationVersion: get Implementation Version.
 */
static int do_implementationVersion (void *obj, Tcl_Interp *interp,
                                     int argc, char **argv)
{
    IrTcl_Obj *p = obj;

    if (argc == 0)
        return ir_tcl_strdup (interp, &p->implementationVersion, 
                          "YAZ: " YAZ_VERSION " / IrTcl: " IR_TCL_VERSION);
    else if (argc == -1)
        return ir_tcl_strdel (interp, &p->implementationVersion);
    Tcl_AppendResult (interp, p->implementationVersion, (char*) NULL);
    return TCL_OK;
}

/*
 * do_targetImplementationName: Get Implementation Name of target.
 */
static int do_targetImplementationName (void *obj, Tcl_Interp *interp,
                                        int argc, char **argv)
{
    IrTcl_Obj *p = obj;
    
    if (argc == 0)
    {
        p->targetImplementationName = NULL;
	return TCL_OK;
    }
    else if (argc == -1)
        return ir_tcl_strdel (interp, &p->targetImplementationName);
    Tcl_AppendResult (interp, p->targetImplementationName, (char*) NULL);
    return TCL_OK;
}

/*
 * do_targetImplementationId: Get Implementation Id of target
 */
static int do_targetImplementationId (void *obj, Tcl_Interp *interp,
                                      int argc, char **argv)
{
    IrTcl_Obj *p = obj;

    if (argc == 0)
    {
        p->targetImplementationId = NULL;
	return TCL_OK;
    }
    else if (argc == -1)
        return ir_tcl_strdel (interp, &p->targetImplementationId);
    Tcl_AppendResult (interp, p->targetImplementationId, (char*) NULL);
    return TCL_OK;
}

/*
 * do_targetImplementationVersion: Get Implementation Version of target
 */
static int do_targetImplementationVersion (void *obj, Tcl_Interp *interp,
                                           int argc, char **argv)
{
    IrTcl_Obj *p = obj;

    if (argc == 0)
    {
        p->targetImplementationVersion = NULL;
	return TCL_OK;
    }
    else if (argc == -1)
        return ir_tcl_strdel (interp, &p->targetImplementationVersion);
    Tcl_AppendResult (interp, p->targetImplementationVersion, (char*) NULL);
    return TCL_OK;
}

/*
 * do_idAuthentication: Set/get id Authentication
 */
static int do_idAuthentication (void *obj, Tcl_Interp *interp,
                                int argc, char **argv)
{
    IrTcl_Obj *p = obj;

    if (argc >= 3 || argc == -1)
    {
        free (p->idAuthenticationOpen);
        free (p->idAuthenticationGroupId);
        free (p->idAuthenticationUserId);
        free (p->idAuthenticationPassword);
    }
    if (argc >= 3 || argc <= 0)
    {
        p->idAuthenticationOpen = NULL;
        p->idAuthenticationGroupId = NULL;
        p->idAuthenticationUserId = NULL;
        p->idAuthenticationPassword = NULL;
    }
    if (argc <= 0)
        return TCL_OK;
    if (argc >= 3)
    {
        if (argc == 3)
        {
            if (ir_tcl_strdup (interp, &p->idAuthenticationOpen, argv[2])
                == TCL_ERROR)
                return TCL_ERROR;
        }
        else if (argc == 5)
        {
            if (ir_tcl_strdup (interp, &p->idAuthenticationGroupId, argv[2])
                == TCL_ERROR)
                return TCL_ERROR;
            if (ir_tcl_strdup (interp, &p->idAuthenticationUserId, argv[3])
                == TCL_ERROR)
                return TCL_ERROR;
            if (ir_tcl_strdup (interp, &p->idAuthenticationPassword, argv[4])
                == TCL_ERROR)
                return TCL_ERROR;
        }
    }
    if (p->idAuthenticationOpen)
        Tcl_AppendElement (interp, p->idAuthenticationOpen);
    else if (p->idAuthenticationGroupId)
    {
        Tcl_AppendElement (interp, p->idAuthenticationGroupId);
        Tcl_AppendElement (interp, p->idAuthenticationUserId);
        Tcl_AppendElement (interp, p->idAuthenticationPassword);
    }
    return TCL_OK;
}

/*
 * do_connect: connect method on IR object
 */
static int do_connect (void *obj, Tcl_Interp *interp,
		       int argc, char **argv)
{
    void *addr;
    IrTcl_Obj *p = obj;
    int r;

    if (argc <= 0)
        return TCL_OK;
    if (argc == 3)
    {
        if (p->hostname)
        {
            interp->result = "already connected";
            return TCL_ERROR;
        }
        if (ir_tcl_strdup (interp, &p->hostname, argv[2]) == TCL_ERROR)
            return TCL_ERROR;
        if (!strcmp (p->cs_type, "tcpip"))
        {
            p->cs_link = cs_create (tcpip_type, CS_BLOCK, p->protocol_type);
            addr = tcpip_strtoaddr (argv[2]);
            if (!addr)
            {
                interp->result = "tcpip_strtoaddr fail";
                return TCL_ERROR;
            }
            logf (LOG_DEBUG, "tcp/ip connect %s", argv[2]);
        }
        else if (!strcmp (p->cs_type, "mosi"))
        {
#if MOSI
            p->cs_link = cs_create (mosi_type, CS_BLOCK, p->protocol_type);
            addr = mosi_strtoaddr (argv[2]);
            if (!addr)
            {
                interp->result = "mosi_strtoaddr fail";
                return TCL_ERROR;
            }
            logf (LOG_DEBUG, "mosi connect %s", argv[2]);
#else
            interp->result = "MOSI support not there";
            return TCL_ERROR;
#endif
        }
        else 
        {
            Tcl_AppendResult (interp, "Bad comstack type: ", 
                              p->cs_type, NULL);
            return TCL_ERROR;
        }
        if ((r=cs_connect (p->cs_link, addr)) < 0)
        {
            interp->result = "connect fail";
            do_disconnect (p, NULL, 2, NULL);
            return TCL_ERROR;
        }
        ir_select_add (cs_fileno (p->cs_link), p);
        if (r == 1)
        {
            ir_select_add_write (cs_fileno (p->cs_link), p);
            p->state = IR_TCL_R_Connecting;
        }
        else
        {
            p->state = IR_TCL_R_Idle;
            if (p->callback)
                IrTcl_eval (p->interp, p->callback);
        }
    }
    else
        Tcl_AppendResult (interp, p->hostname, NULL);
    return TCL_OK;
}

/*
 * do_disconnect: disconnect method on IR object
 */
static int do_disconnect (void *obj, Tcl_Interp *interp,
                          int argc, char **argv)
{
    IrTcl_Obj *p = obj;

    if (argc == 0)
    {
        p->state = IR_TCL_R_Idle;
        p->hostname = NULL;
	p->cs_link = NULL;
        return TCL_OK;
    }
    if (p->hostname)
    {
        free (p->hostname);
        p->hostname = NULL;
        ir_select_remove_write (cs_fileno (p->cs_link), p);
        ir_select_remove (cs_fileno (p->cs_link), p);

        odr_reset (p->odr_in);

        assert (p->cs_link);
        cs_close (p->cs_link);
        p->cs_link = NULL;

        ODR_MASK_ZERO (&p->options);
	ODR_MASK_SET (&p->options, 0);
	ODR_MASK_SET (&p->options, 1);
	ODR_MASK_SET (&p->options, 4);
	ODR_MASK_SET (&p->options, 7);
	ODR_MASK_SET (&p->options, 14);

        ODR_MASK_ZERO (&p->protocolVersion);
	ODR_MASK_SET (&p->protocolVersion, 0);
	ODR_MASK_SET (&p->protocolVersion, 1);
        ir_tcl_del_q (p);
    }
    assert (!p->cs_link);
    return TCL_OK;
}

/*
 * do_comstack: Set/get comstack method on IR object
 */
static int do_comstack (void *o, Tcl_Interp *interp,
		        int argc, char **argv)
{
    IrTcl_Obj *obj = o;

    if (argc == 0)
        return ir_tcl_strdup (interp, &obj->cs_type, "tcpip");
    else if (argc == -1)
        return ir_tcl_strdel (interp, &obj->cs_type);
    else if (argc == 3)
    {
        free (obj->cs_type);
        if (ir_tcl_strdup (interp, &obj->cs_type, argv[2]) == TCL_ERROR)
            return TCL_ERROR;
    }
    Tcl_AppendElement (interp, obj->cs_type);
    return TCL_OK;
}

/*
 * do_logLevel: Set log level
 */
static int do_logLevel (void *o, Tcl_Interp *interp,
                        int argc, char **argv)
{
    if (argc <= 2)
        return TCL_OK;
    if (argc == 3)
        log_init (log_mask_str (argv[2]), "", NULL);
    else if (argc == 4)
        log_init (log_mask_str (argv[2]), argv[3], NULL);
    else if (argc == 5)
        log_init (log_mask_str (argv[2]), argv[3], argv[4]);
    return TCL_OK;
}


/*
 * do_callback: add callback
 */
static int do_callback (void *obj, Tcl_Interp *interp,
                          int argc, char **argv)
{
    IrTcl_Obj *p = obj;

    if (argc == 0)
    {
        p->callback = NULL;
	return TCL_OK;
    }
    else if (argc == -1)
        return ir_tcl_strdel (interp, &p->callback);
    if (argc == 3)
    {
        free (p->callback);
	if (argv[2][0])
	{
            if (ir_tcl_strdup (interp, &p->callback, argv[2]) == TCL_ERROR)
                return TCL_ERROR;
	}
	else
	    p->callback = NULL;
    }
    return TCL_OK;
}

/*
 * do_failback: add error handle callback
 */
static int do_failback (void *obj, Tcl_Interp *interp,
                          int argc, char **argv)
{
    IrTcl_Obj *p = obj;

    if (argc == 0)
    {
        p->failback = NULL;
	return TCL_OK;
    }
    else if (argc == -1)
        return ir_tcl_strdel (interp, &p->failback);
    else if (argc == 3)
    {
        free (p->failback);
	if (argv[2][0])
	{
            if (ir_tcl_strdup (interp, &p->failback, argv[2]) == TCL_ERROR)
                return TCL_ERROR;
	}
	else
	    p->failback = NULL;
    }
    return TCL_OK;
}

/*
 * do_protocol: Set/get protocol method on IR object
 */
static int do_protocol (void *o, Tcl_Interp *interp, int argc, char **argv)
{
    IrTcl_Obj *p = o;

    if (argc <= 0)
    {
        p->protocol_type = PROTO_Z3950;
        return TCL_OK;
    }
    else if (argc == 3)
    {
        if (!strcmp (argv[2], "Z39"))
            p->protocol_type = PROTO_Z3950;
        else if (!strcmp (argv[2], "SR"))
            p->protocol_type = PROTO_SR;
        else
        {
            Tcl_AppendResult (interp, "Bad protocol: ", argv[2], NULL);
            return TCL_ERROR;
        }
        return TCL_OK;
    }
    switch (p->protocol_type)
    {
    case PROTO_Z3950:
        Tcl_AppendElement (interp, "Z39");
        break;
    case PROTO_SR:
        Tcl_AppendElement (interp, "SR");
        break;
    }
    return TCL_OK;
}

/*
 * do_triggerResourceControl:
 */
static int do_triggerResourceControl (void *obj, Tcl_Interp *interp,
                                      int argc, char **argv)
{
    IrTcl_Obj *p = obj;
    Z_APDU *apdu;
    Z_TriggerResourceControlRequest *req;
    bool_t is_false = 0;

    if (argc <= 0)
        return TCL_OK;
    if (!p->cs_link)
    {
        interp->result = "triggerResourceControl: not connected";
        return TCL_ERROR;
    }
    apdu = zget_APDU (p->odr_out, Z_APDU_triggerResourceControlRequest);
    req = apdu->u.triggerResourceControlRequest;
    *req->requestedAction = Z_TriggerResourceCtrl_cancel;
    req->resultSetWanted = &is_false; 
    
    return ir_tcl_send_APDU (interp, p, apdu, "triggerResourceControl",
                             argv[0]);
}

/*
 * do_databaseNames: specify database names
 */
static int do_databaseNames (void *obj, Tcl_Interp *interp,
                             int argc, char **argv)
{
    int i;
    IrTcl_SetCObj *p = obj;

    if (argc == -1)
    {
        for (i=0; i<p->num_databaseNames; i++)
            free (p->databaseNames[i]);
        free (p->databaseNames);
    }
    if (argc <= 0)
    {
        p->num_databaseNames = 0;
	p->databaseNames = NULL;
	return TCL_OK;
    }
    if (argc < 3)
    {
        for (i=0; i<p->num_databaseNames; i++)
            Tcl_AppendElement (interp, p->databaseNames[i]);
        return TCL_OK;
    }
    if (p->databaseNames)
    {
        for (i=0; i<p->num_databaseNames; i++)
            free (p->databaseNames[i]);
        free (p->databaseNames);
    }
    p->num_databaseNames = argc - 2;
    p->databaseNames =
        ir_tcl_malloc (sizeof(*p->databaseNames) * p->num_databaseNames);
    for (i=0; i<p->num_databaseNames; i++)
    {
        if (ir_tcl_strdup (interp, &p->databaseNames[i], argv[2+i]) 
            == TCL_ERROR)
            return TCL_ERROR;
    }
    return TCL_OK;
}

/*
 * do_replaceIndicator: Set/get replace Set indicator
 */
static int do_replaceIndicator (void *obj, Tcl_Interp *interp,
                                int argc, char **argv)
{
    IrTcl_SetCObj *p = obj;

    if (argc <= 0)
    {
        p->replaceIndicator = 1;
	return TCL_OK;
    }
    return get_set_int (&p->replaceIndicator, interp, argc, argv);
}

/*
 * do_queryType: Set/Get query method
 */
static int do_queryType (void *obj, Tcl_Interp *interp,
		       int argc, char **argv)
{
    IrTcl_SetCObj *p = obj;

    if (argc == 0)
        return ir_tcl_strdup (interp, &p->queryType, "rpn");
    else if (argc == -1)
        return ir_tcl_strdel (interp, &p->queryType);
    if (argc == 3)
    {
        free (p->queryType);
        if (ir_tcl_strdup (interp, &p->queryType, argv[2]) == TCL_ERROR)
            return TCL_ERROR;
    }
    Tcl_AppendResult (interp, p->queryType, NULL);
    return TCL_OK;
}

/*
 * do_userInformationField: Get User information field
 */
static int do_userInformationField (void *obj, Tcl_Interp *interp,
                                    int argc, char **argv)
{
    IrTcl_Obj *p = obj;
    
    if (argc == 0)
    {
        p->userInformationField = NULL;
	return TCL_OK;
    }
    else if (argc == -1)
        return ir_tcl_strdel (interp, &p->userInformationField);
    Tcl_AppendResult (interp, p->userInformationField, NULL);
    return TCL_OK;
}

/*
 * do_smallSetUpperBound: Set/get small set upper bound
 */
static int do_smallSetUpperBound (void *o, Tcl_Interp *interp,
		       int argc, char **argv)
{
    IrTcl_SetCObj *p = o;

    if (argc <= 0)
    {
        p->smallSetUpperBound = 0;
	return TCL_OK;
    }
    return get_set_int (&p->smallSetUpperBound, interp, argc, argv);
}

/*
 * do_largeSetLowerBound: Set/get large set lower bound
 */
static int do_largeSetLowerBound (void *o, Tcl_Interp *interp,
                                  int argc, char **argv)
{
    IrTcl_SetCObj *p = o;

    if (argc <= 0)
    {
        p->largeSetLowerBound = 2;
	return TCL_OK;
    }
    return get_set_int (&p->largeSetLowerBound, interp, argc, argv);
}

/*
 * do_mediumSetPresentNumber: Set/get large set lower bound
 */
static int do_mediumSetPresentNumber (void *o, Tcl_Interp *interp,
                                      int argc, char **argv)
{
    IrTcl_SetCObj *p = o;
   
    if (argc <= 0)
    {
        p->mediumSetPresentNumber = 0;
	return TCL_OK;
    }
    return get_set_int (&p->mediumSetPresentNumber, interp, argc, argv);
}

/*
 * do_referenceId: Set/Get referenceId
 */
static int do_referenceId (void *obj, Tcl_Interp *interp,
		           int argc, char **argv)
{
    IrTcl_SetCObj *p = obj;

    if (argc == 0)
    {
        p->referenceId = NULL;
        return TCL_OK;
    }
    else if (argc == -1)
        return ir_tcl_strdel (interp, &p->referenceId);
    if (argc == 3)
    {
        free (p->referenceId);
        if (ir_tcl_strdup (interp, &p->referenceId, argv[2]) == TCL_ERROR)
            return TCL_ERROR;
    }
    Tcl_AppendResult (interp, p->referenceId, NULL);
    return TCL_OK;
}

/*
 * do_preferredRecordSyntax: Set/get preferred record syntax
 */
static int do_preferredRecordSyntax (void *obj, Tcl_Interp *interp,
                                     int argc, char **argv)
{
    IrTcl_SetCObj *p = obj;

    if (argc == 0)
    {
        p->preferredRecordSyntax = NULL;
        return TCL_OK;
    }
    else if (argc == -1)
    {
        free (p->preferredRecordSyntax);
        p->preferredRecordSyntax = NULL;
        return TCL_OK;
    }
    if (argc == 3)
    {
        free (p->preferredRecordSyntax);
        p->preferredRecordSyntax = NULL;
        if (argv[2][0] && (p->preferredRecordSyntax = 
                           ir_tcl_malloc (sizeof(*p->preferredRecordSyntax))))
            *p->preferredRecordSyntax = IrTcl_getRecordSyntaxVal (argv[2]);
    }
    return TCL_OK;
            
}

/*
 * do_elementSetNames: Set/Get element Set Names
 */
static int do_elementSetNames (void *obj, Tcl_Interp *interp,
                               int argc, char **argv)
{
    IrTcl_SetCObj *p = obj;

    if (argc == 0)
    {
        p->elementSetNames = NULL;
        return TCL_OK;
    }
    else if (argc == -1)
        return ir_tcl_strdel (interp, &p->elementSetNames);
    if (argc == 3)
    {
        free (p->elementSetNames);
        if (ir_tcl_strdup (interp, &p->elementSetNames, argv[2]) == TCL_ERROR)
            return TCL_ERROR;
    }
    Tcl_AppendResult (interp, p->elementSetNames, NULL);
    return TCL_OK;
}

/*
 * do_smallSetElementSetNames: Set/Get small Set Element Set Names
 */
static int do_smallSetElementSetNames (void *obj, Tcl_Interp *interp,
                               int argc, char **argv)
{
    IrTcl_SetCObj *p = obj;

    if (argc == 0)
    {
        p->smallSetElementSetNames = NULL;
        return TCL_OK;
    }
    else if (argc == -1)
        return ir_tcl_strdel (interp, &p->smallSetElementSetNames);
    if (argc == 3)
    {
        free (p->smallSetElementSetNames);
        if (ir_tcl_strdup (interp, &p->smallSetElementSetNames,
                           argv[2]) == TCL_ERROR)
            return TCL_ERROR;
    }
    Tcl_AppendResult (interp, p->smallSetElementSetNames, NULL);
    return TCL_OK;
}

/*
 * do_mediumSetElementSetNames: Set/Get medium Set Element Set Names
 */
static int do_mediumSetElementSetNames (void *obj, Tcl_Interp *interp,
                               int argc, char **argv)
{
    IrTcl_SetCObj *p = obj;

    if (argc == 0)
    {
        p->mediumSetElementSetNames = NULL;
        return TCL_OK;
    }
    else if (argc == -1)
        return ir_tcl_strdel (interp, &p->mediumSetElementSetNames);
    if (argc == 3)
    {
        free (p->mediumSetElementSetNames);
        if (ir_tcl_strdup (interp, &p->mediumSetElementSetNames,
                           argv[2]) == TCL_ERROR)
            return TCL_ERROR;
    }
    Tcl_AppendResult (interp, p->mediumSetElementSetNames, NULL);
    return TCL_OK;
}


static IrTcl_Method ir_method_tab[] = {
{ 1, "comstack",                    do_comstack },
{ 1, "protocol",                    do_protocol },
{ 0, "failback",                    do_failback },
{ 0, "failInfo",                    do_failInfo },
{ 0, "logLevel",                    do_logLevel },

{ 1, "connect",                     do_connect },
{ 0, "protocolVersion",             do_protocolVersion },
{ 1, "preferredMessageSize",        do_preferredMessageSize },
{ 1, "maximumRecordSize",           do_maximumRecordSize },
{ 1, "implementationName",          do_implementationName },
{ 1, "implementationId",            do_implementationId },
{ 1, "implementationVersion",       do_implementationVersion },
{ 0, "targetImplementationName",    do_targetImplementationName },
{ 0, "targetImplementationId",      do_targetImplementationId },
{ 0, "targetImplementationVersion", do_targetImplementationVersion },
{ 0, "userInformationField",        do_userInformationField },
{ 1, "idAuthentication",            do_idAuthentication },
{ 0, "options",                     do_options },
{ 0, "init",                        do_init_request },
{ 0, "initResult",                  do_initResult },
{ 0, "disconnect",                  do_disconnect },
{ 0, "callback",                    do_callback },
{ 0, "triggerResourceControl",      do_triggerResourceControl },
{ 0, NULL, NULL}
};

static IrTcl_Method ir_set_c_method_tab[] = {
{ 0, "databaseNames",               do_databaseNames},
{ 0, "replaceIndicator",            do_replaceIndicator},
{ 0, "queryType",                   do_queryType },
{ 0, "preferredRecordSyntax",       do_preferredRecordSyntax },
{ 0, "smallSetUpperBound",          do_smallSetUpperBound},
{ 0, "largeSetLowerBound",          do_largeSetLowerBound},
{ 0, "mediumSetPresentNumber",      do_mediumSetPresentNumber},
{ 0, "referenceId",                 do_referenceId },
{ 0, "elementSetNames",             do_elementSetNames },
{ 0, "smallSetElementSetNames",     do_smallSetElementSetNames },
{ 0, "mediumSetElementSetNames",    do_mediumSetElementSetNames },
{ 0, NULL, NULL}
};

/* 
 * ir_obj_method: IR Object methods
 */
static int ir_obj_method (ClientData clientData, Tcl_Interp *interp,
                          int argc, char **argv)
{
    IrTcl_Methods tab[3];
    IrTcl_Obj *p = clientData;

    if (argc < 2)
        return ir_method_r (clientData, interp, argc, argv, ir_method_tab);

    tab[0].tab = ir_method_tab;
    tab[0].obj = p;
    tab[1].tab = ir_set_c_method_tab;
    tab[1].obj = &p->set_inher;
    tab[2].tab = NULL;

    return ir_method (interp, argc, argv, tab);
}

/* 
 * ir_obj_delete: IR Object disposal
 */
static void ir_obj_delete (ClientData clientData)
{
    IrTcl_Obj *obj = clientData;
    IrTcl_Methods tab[3];

    --(obj->ref_count);
    if (obj->ref_count > 0)
        return;
    assert (obj->ref_count == 0);

    logf (LOG_DEBUG, "ir object delete");
    tab[0].tab = ir_method_tab;
    tab[0].obj = obj;
    tab[1].tab = ir_set_c_method_tab;
    tab[1].obj = &obj->set_inher;
    tab[2].tab = NULL;

    ir_method (NULL, -1, NULL, tab);

    ir_tcl_del_q (obj);
    odr_destroy (obj->odr_in);
    odr_destroy (obj->odr_out);
    odr_destroy (obj->odr_pr);
    free (obj);
}

/* 
 * ir_obj_mk: IR Object creation
 */
static int ir_obj_mk (ClientData clientData, Tcl_Interp *interp,
                      int argc, char **argv)
{
    IrTcl_Methods tab[3];
    IrTcl_Obj *obj;
#if CCL2RPN
    FILE *inf;
#endif

    if (argc != 2)
    {
        interp->result = "wrong # args";
        return TCL_ERROR;
    }
    obj = ir_tcl_malloc (sizeof(*obj));
    obj->ref_count = 1;
#if CCL2RPN
    obj->bibset = ccl_qual_mk (); 
    if ((inf = fopen ("default.bib", "r")))
    {
    	ccl_qual_file (obj->bibset, inf);
    	fclose (inf);
    }
#endif

    logf (LOG_DEBUG, "ir object create");
    obj->odr_in = odr_createmem (ODR_DECODE);
    obj->odr_out = odr_createmem (ODR_ENCODE);
    obj->odr_pr = odr_createmem (ODR_PRINT);
    obj->state = IR_TCL_R_Idle;
    obj->interp = interp;

    obj->len_in = 0;
    obj->buf_in = NULL;
    obj->request_queue = NULL;

    tab[0].tab = ir_method_tab;
    tab[0].obj = obj;
    tab[1].tab = ir_set_c_method_tab;
    tab[1].obj = &obj->set_inher;
    tab[2].tab = NULL;

    if (ir_method (interp, 0, NULL, tab) == TCL_ERROR)
        return TCL_ERROR;
    Tcl_CreateCommand (interp, argv[1], ir_obj_method,
                       (ClientData) obj, ir_obj_delete);
    return TCL_OK;
}

/* ------------------------------------------------------- */
/*
 * do_search: Do search request
 */
static int do_search (void *o, Tcl_Interp *interp, int argc, char **argv)
{
    Z_SearchRequest *req;
    Z_Query query;
    Z_APDU *apdu;
    Odr_oct ccl_query;
    IrTcl_SetObj *obj = o;
    IrTcl_Obj *p;
    int r;
    oident bib1;

    if (argc <= 0)
        return TCL_OK;

    p = obj->parent;
    if (argc != 3)
    {
        interp->result = "wrong # args";
        return TCL_ERROR;
    }
    if (!obj->set_inher.num_databaseNames)
    {
        interp->result = "no databaseNames";
        return TCL_ERROR;
    }
    if (!p->cs_link)
    {
        interp->result = "search: not connected";
        return TCL_ERROR;
    }
    apdu = zget_APDU (p->odr_out, Z_APDU_searchRequest);
    req = apdu->u.searchRequest;

    obj->start = 1;

    bib1.proto = p->protocol_type;
    bib1.class = CLASS_ATTSET;
    bib1.value = VAL_BIB1;

    set_referenceId (p->odr_out, &req->referenceId,
                     obj->set_inher.referenceId);

    req->smallSetUpperBound = &obj->set_inher.smallSetUpperBound;
    req->largeSetLowerBound = &obj->set_inher.largeSetLowerBound;
    req->mediumSetPresentNumber = &obj->set_inher.mediumSetPresentNumber;
    req->replaceIndicator = &obj->set_inher.replaceIndicator;
    req->resultSetName = obj->setName ? obj->setName : "Default";
    logf (LOG_DEBUG, "Search, resultSetName %s", req->resultSetName);
    req->num_databaseNames = obj->set_inher.num_databaseNames;
    req->databaseNames = obj->set_inher.databaseNames;
    for (r=0; r < obj->set_inher.num_databaseNames; r++)
        logf (LOG_DEBUG, " Database %s", obj->set_inher.databaseNames[r]);
    if (obj->set_inher.preferredRecordSyntax)
    {
        struct oident ident;

        ident.proto = p->protocol_type;
        ident.class = CLASS_RECSYN;
        ident.value = *obj->set_inher.preferredRecordSyntax;
        logf (LOG_DEBUG, "Preferred record syntax is %d", ident.value);
        req->preferredRecordSyntax = odr_oiddup (p->odr_out, 
                                                 oid_getoidbyent (&ident));
    }
    else
        req->preferredRecordSyntax = 0;

    if (obj->set_inher.smallSetElementSetNames &&
        *obj->set_inher.smallSetElementSetNames)
    {
        Z_ElementSetNames *esn = odr_malloc (p->odr_out, sizeof(*esn));
        
        esn->which = Z_ElementSetNames_generic;
        esn->u.generic = obj->set_inher.elementSetNames;
        req->smallSetElementSetNames = esn;
    }
    else
        req->smallSetElementSetNames = NULL; 
    
    if (obj->set_inher.mediumSetElementSetNames &&
        *obj->set_inher.mediumSetElementSetNames)
    {
        Z_ElementSetNames *esn = odr_malloc (p->odr_out, sizeof(*esn));
        
        esn->which = Z_ElementSetNames_generic;
        esn->u.generic = obj->set_inher.elementSetNames;
        req->mediumSetElementSetNames = esn;
    }
    else
        req->mediumSetElementSetNames = NULL; 
    
    req->query = &query;
    
    if (!strcmp (obj->set_inher.queryType, "rpn"))
    {
        Z_RPNQuery *RPNquery;

        RPNquery = p_query_rpn (p->odr_out, argv[2]);
	if (!RPNquery)
	{
            Tcl_AppendResult (interp, "Syntax error in query", NULL);
            return TCL_ERROR;
        }
        RPNquery->attributeSetId = oid_getoidbyent (&bib1);
        query.which = Z_Query_type_1;
        query.u.type_1 = RPNquery;
        logf (LOG_DEBUG, "RPN");
    }
#if CCL2RPN
    else if (!strcmp (obj->set_inher.queryType, "cclrpn"))
    {
        int error;
        int pos;
        struct ccl_rpn_node *rpn;
        Z_RPNQuery *RPNquery;

        rpn = ccl_find_str(p->bibset, argv[2], &error, &pos);
        if (error)
        {
            Tcl_AppendResult (interp, "CCL error: ", 
	                      ccl_err_msg(error), NULL);
            return TCL_ERROR;
        }
        ccl_pr_tree (rpn, stderr);
        fprintf (stderr, "\n");
        assert((RPNquery = ccl_rpn_query(rpn)));
        RPNquery->attributeSetId = oid_getoidbyent (&bib1);
        query.which = Z_Query_type_1;
        query.u.type_1 = RPNquery;
        logf (LOG_DEBUG, "CCLRPN");
    }
#endif
    else if (!strcmp (obj->set_inher.queryType, "ccl"))
    {
        query.which = Z_Query_type_2;
        query.u.type_2 = &ccl_query;
        ccl_query.buf = (unsigned char *) argv[2];
        ccl_query.len = strlen (argv[2]);
        logf (LOG_DEBUG, "CCL");
    }
    else
    {
        interp->result = "unknown query method";
        return TCL_ERROR;
    }
    return ir_tcl_send_APDU (interp, p, apdu, "search", argv[0]);
}

/*
 * do_resultCount: Get number of hits
 */
static int do_resultCount (void *o, Tcl_Interp *interp,
		       int argc, char **argv)
{
    IrTcl_SetObj *obj = o;

    if (argc <= 0)
        return TCL_OK;
    return get_set_int (&obj->resultCount, interp, argc, argv);
}

/*
 * do_searchStatus: Get search status (after search response)
 */
static int do_searchStatus (void *o, Tcl_Interp *interp,
		            int argc, char **argv)
{
    IrTcl_SetObj *obj = o;

    if (argc <= 0)
        return TCL_OK;
    return get_set_int (&obj->searchStatus, interp, argc, argv);
}

/*
 * do_presentStatus: Get search status (after search/present response)
 */
static int do_presentStatus (void *o, Tcl_Interp *interp,
		            int argc, char **argv)
{
    IrTcl_SetObj *obj = o;

    if (argc <= 0)
        return TCL_OK;
    return get_set_int (&obj->presentStatus, interp, argc, argv);
}

/*
 * do_nextResultSetPosition: Get next result set position
 *       (after search/present response)
 */
static int do_nextResultSetPosition (void *o, Tcl_Interp *interp,
                                     int argc, char **argv)
{
    IrTcl_SetObj *obj = o;

    if (argc <= 0)
    {
        obj->nextResultSetPosition = 0;
        return TCL_OK;
    }
    return get_set_int (&obj->nextResultSetPosition, interp, argc, argv);
}

/*
 * do_setName: Set result Set name
 */
static int do_setName (void *o, Tcl_Interp *interp,
		       int argc, char **argv)
{
    IrTcl_SetObj *obj = o;

    if (argc == 0)
        return ir_tcl_strdup (interp, &obj->setName, "Default");
    else if (argc == -1)
        return ir_tcl_strdel (interp, &obj->setName);
    if (argc == 3)
    {
        free (obj->setName);
        if (ir_tcl_strdup (interp, &obj->setName, argv[2])
            == TCL_ERROR)
            return TCL_ERROR;
    }
    Tcl_AppendElement (interp, obj->setName);
    return TCL_OK;
}

/*
 * do_numberOfRecordsReturned: Get number of records returned
 */
static int do_numberOfRecordsReturned (void *o, Tcl_Interp *interp,
                                       int argc, char **argv)
{
    IrTcl_SetObj *obj = o;

    if (argc <= 0)
    {
        obj->numberOfRecordsReturned = 0;
        return TCL_OK;
    }
    return get_set_int (&obj->numberOfRecordsReturned, interp, argc, argv);
}

/*
 * do_type: Return type (if any) at position.
 */
static int do_type (void *o, Tcl_Interp *interp, int argc, char **argv)
{
    IrTcl_SetObj *obj = o;
    int offset;
    IrTcl_RecordList *rl;

    if (argc == 0)
    {
        obj->record_list = NULL;
	return TCL_OK;
    }
    else if (argc == -1)
    {
        delete_IR_records (obj);
	return TCL_OK;
    }
    if (argc < 3)
    {
        sprintf (interp->result, "wrong # args");
        return TCL_ERROR;
    }
    if (Tcl_GetInt (interp, argv[2], &offset)==TCL_ERROR)
        return TCL_ERROR;
    rl = find_IR_record (obj, offset);
    if (!rl)
    {
        logf (LOG_DEBUG, "No record at position %d", offset);
        return TCL_OK;
    }
    switch (rl->which)
    {
    case Z_NamePlusRecord_databaseRecord:
        interp->result = "DB";
        break;
    case Z_NamePlusRecord_surrogateDiagnostic:
        interp->result = "SD";
        break;
    }
    return TCL_OK;
}


/*
 * do_recordType: Return record type (if any) at position.
 */
static int do_recordType (void *o, Tcl_Interp *interp, int argc, char **argv)
{
    IrTcl_SetObj *obj = o;
    int offset;
    IrTcl_RecordList *rl;

    if (argc == 0)
    {
	return TCL_OK;
    }
    else if (argc == -1)
    {
	return TCL_OK;
    }
    if (argc < 3)
    {
        sprintf (interp->result, "wrong # args");
        return TCL_ERROR;
    }
    if (Tcl_GetInt (interp, argv[2], &offset)==TCL_ERROR)
        return TCL_ERROR;
    rl = find_IR_record (obj, offset);
    if (!rl)
        return TCL_OK;
    if (rl->which != Z_NamePlusRecord_databaseRecord)
    {
        Tcl_AppendResult (interp, "No DB record at #", argv[2], NULL);
        return TCL_ERROR;
    }
    Tcl_AppendElement (interp, (char*)
                       IrTcl_getRecordSyntaxStr (rl->u.dbrec.type));
    return TCL_OK;
}

/*
 * ir_diagResult 
 */
static int ir_diagResult (Tcl_Interp *interp, IrTcl_Diagnostic *list, int num)
{
    char buf[20];
    int i;
    const char *cp;

    for (i = 0; i<num; i++)
    {
        logf (LOG_DEBUG, "Diagnostic, code %d", list[i].condition);
        sprintf (buf, "%d", list[i].condition);
        Tcl_AppendElement (interp, buf);
        cp = diagbib1_str (list[i].condition);
        if (cp)
            Tcl_AppendElement (interp, (char*) cp);
        else
            Tcl_AppendElement (interp, "");
        if (list[i].addinfo)
            Tcl_AppendElement (interp, (char*) list[i].addinfo);
        else
            Tcl_AppendElement (interp, "");
    }
    return TCL_OK;
}

/*
 * do_diag: Return diagnostic record info
 */
static int do_diag (void *o, Tcl_Interp *interp, int argc, char **argv)
{
    IrTcl_SetObj *obj = o;
    int offset;
    IrTcl_RecordList *rl;

    if (argc <= 0)
        return TCL_OK;
    if (argc < 3)
    {
        sprintf (interp->result, "wrong # args");
        return TCL_ERROR;
    }
    if (Tcl_GetInt (interp, argv[2], &offset)==TCL_ERROR)
        return TCL_ERROR;
    rl = find_IR_record (obj, offset);
    if (!rl)
    {
        Tcl_AppendResult (interp, "No record at #", argv[2], NULL);
        return TCL_ERROR;
    }
    if (rl->which != Z_NamePlusRecord_surrogateDiagnostic)
    {
        Tcl_AppendResult (interp, "No Diagnostic record at #", argv[2], NULL);
        return TCL_ERROR;
    }
    return ir_diagResult (interp, rl->u.surrogateDiagnostics.list,
                          rl->u.surrogateDiagnostics.num);
}

/*
 * do_getMarc: Get ISO2709 Record lines/fields
 */
static int do_getMarc (void *o, Tcl_Interp *interp, int argc, char **argv)
{
    IrTcl_SetObj *obj = o;
    int offset;
    IrTcl_RecordList *rl;

    if (argc <= 0)
        return TCL_OK;
    if (argc < 7)
    {
        sprintf (interp->result, "wrong # args");
        return TCL_ERROR;
    }
    if (Tcl_GetInt (interp, argv[2], &offset)==TCL_ERROR)
        return TCL_ERROR;
    rl = find_IR_record (obj, offset);
    if (!rl)
    {
        Tcl_AppendResult (interp, "No record at #", argv[2], NULL);
        return TCL_ERROR;
    }
    if (rl->which != Z_NamePlusRecord_databaseRecord)
    {
        Tcl_AppendResult (interp, "No DB record at #", argv[2], NULL);
        return TCL_ERROR;
    }
    return ir_tcl_get_marc (interp, rl->u.dbrec.buf, argc, argv);
}

/*
 * do_getSutrs: Get SUTRS Record
 */
static int do_getSutrs (void *o, Tcl_Interp *interp, int argc, char **argv)
{
    IrTcl_SetObj *obj = o;
    int offset;
    IrTcl_RecordList *rl;

    if (argc <= 0)
        return TCL_OK;
    if (argc < 3)
    {
        sprintf (interp->result, "wrong # args");
        return TCL_ERROR;
    }
    if (Tcl_GetInt (interp, argv[2], &offset)==TCL_ERROR)
        return TCL_ERROR;
    rl = find_IR_record (obj, offset);
    if (!rl)
    {
        Tcl_AppendResult (interp, "No record at #", argv[2], NULL);
        return TCL_ERROR;
    }
    if (rl->which != Z_NamePlusRecord_databaseRecord)
    {
        Tcl_AppendResult (interp, "No DB record at #", argv[2], NULL);
        return TCL_ERROR;
    }
    if (rl->u.dbrec.type != VAL_SUTRS)
        return TCL_OK;
    Tcl_AppendElement (interp, rl->u.dbrec.buf);
    return TCL_OK;
}


/*
 * do_getGrs: Get a GRS1 Record
 */
static int do_getGrs (void *o, Tcl_Interp *interp, int argc, char **argv)
{
    IrTcl_SetObj *obj = o;
    int offset;
    IrTcl_RecordList *rl;

    if (argc <= 0)
        return TCL_OK;
    if (argc < 3)
    {
        sprintf (interp->result, "wrong # args");
        return TCL_ERROR;
    }
    if (Tcl_GetInt (interp, argv[2], &offset)==TCL_ERROR)
        return TCL_ERROR;
    rl = find_IR_record (obj, offset);
    if (!rl)
    {
        Tcl_AppendResult (interp, "No record at #", argv[2], NULL);
        return TCL_ERROR;
    }
    if (rl->which != Z_NamePlusRecord_databaseRecord)
    {
        Tcl_AppendResult (interp, "No DB record at #", argv[2], NULL);
        return TCL_ERROR;
    }
    if (rl->u.dbrec.type != VAL_GRS1)
        return TCL_OK;
    return ir_tcl_get_grs (interp, rl->u.dbrec.u.grs1, argc, argv);
}


/*
 * do_responseStatus: Return response status (present or search)
 */
static int do_responseStatus (void *o, Tcl_Interp *interp, 
                             int argc, char **argv)
{
    IrTcl_SetObj *obj = o;

    if (argc == 0)
    {
        obj->recordFlag = 0;
        obj->nonSurrogateDiagnosticNum = 0;
        obj->nonSurrogateDiagnosticList = NULL;
	return TCL_OK;
    }
    else if (argc == -1)
    {
        ir_deleteDiags (&obj->nonSurrogateDiagnosticList,
                        &obj->nonSurrogateDiagnosticNum);
        return TCL_OK;
    }
    if (!obj->recordFlag)
    {
        Tcl_AppendElement (interp, "OK");
        return TCL_OK;
    }
    switch (obj->which)
    {
    case Z_Records_DBOSD:
    	Tcl_AppendElement (interp, "DBOSD");
        break;
    case Z_Records_NSD:
        Tcl_AppendElement (interp, "NSD");
        return ir_diagResult (interp, obj->nonSurrogateDiagnosticList,
                              obj->nonSurrogateDiagnosticNum);
    }
    return TCL_OK;
}

/*
 * do_present: Perform Present Request
 */

static int do_present (void *o, Tcl_Interp *interp, int argc, char **argv)
{
    IrTcl_SetObj *obj = o;
    IrTcl_Obj *p;
    Z_APDU *apdu;
    Z_PresentRequest *req;
    int start;
    int number;

    if (argc <= 0)
        return TCL_OK;
    if (argc >= 3)
    {
        if (Tcl_GetInt (interp, argv[2], &start) == TCL_ERROR)
            return TCL_ERROR;
    }
    else
        start = 1;
    if (argc >= 4)
    {
        if (Tcl_GetInt (interp, argv[3], &number) == TCL_ERROR)
            return TCL_ERROR;
    }
    else 
        number = 10;
    p = obj->parent;
    if (!p->cs_link)
    {
        interp->result = "present: not connected";
        return TCL_ERROR;
    }

    obj->start = start;
    obj->number = number;

    apdu = zget_APDU (p->odr_out, Z_APDU_presentRequest);
    req = apdu->u.presentRequest;

    set_referenceId (p->odr_out, &req->referenceId,
                     obj->set_inher.referenceId);

    req->resultSetId = obj->setName ? obj->setName : "Default";
    
    req->resultSetStartPoint = &start;
    req->numberOfRecordsRequested = &number;
    if (obj->set_inher.preferredRecordSyntax)
    {
        struct oident ident;

        ident.proto = p->protocol_type;
        ident.class = CLASS_RECSYN;
        ident.value = *obj->set_inher.preferredRecordSyntax;
        logf (LOG_DEBUG, "Preferred record syntax is %d", ident.value);
        req->preferredRecordSyntax = odr_oiddup (p->odr_out, 
                                                 oid_getoidbyent (&ident));
    }
    else
        req->preferredRecordSyntax = 0;

    if (obj->set_inher.elementSetNames && *obj->set_inher.elementSetNames)
    {
        Z_ElementSetNames *esn = odr_malloc (p->odr_out, sizeof(*esn));
        Z_RecordComposition *compo = odr_malloc (p->odr_out, sizeof(*compo));

        esn->which = Z_ElementSetNames_generic;
        esn->u.generic = obj->set_inher.elementSetNames;

        req->recordComposition = compo;
        compo->which = Z_RecordComp_simple;
        compo->u.simple = esn;
    }
    else
        req->recordComposition = NULL;
    return ir_tcl_send_APDU (interp, p, apdu, "present", argv[0]);
}

/*
 * do_loadFile: Load result set from file
 */

static int do_loadFile (void *o, Tcl_Interp *interp,
                        int argc, char **argv)
{
    IrTcl_SetObj *setobj = o;
    FILE *inf;
    size_t size;
    int  no = 1;
    char *buf;

    if (argc <= 0)
        return TCL_OK;
    if (argc < 3)
    {
        interp->result = "wrong # args";
        return TCL_ERROR;
    }
    inf = fopen (argv[2], "r");
    if (!inf)
    {
        Tcl_AppendResult (interp, "Cannot open ", argv[2], NULL);
        return TCL_ERROR;
    }
    while ((buf = ir_tcl_fread_marc (inf, &size)))
    {
        IrTcl_RecordList *rl;

        rl = new_IR_record (setobj, no, Z_NamePlusRecord_databaseRecord);
        rl->u.dbrec.type = VAL_USMARC;
        rl->u.dbrec.buf = buf;
	rl->u.dbrec.size = size;
        no++;
    }
    setobj->numberOfRecordsReturned = no-1;
    fclose (inf);
    return TCL_OK;
}

static IrTcl_Method ir_set_method_tab[] = {
    { 0, "search",                  do_search },
    { 0, "searchStatus",            do_searchStatus },
    { 0, "presentStatus",           do_presentStatus },
    { 0, "nextResultSetPosition",   do_nextResultSetPosition },
    { 0, "setName",                 do_setName },
    { 0, "resultCount",             do_resultCount },
    { 0, "numberOfRecordsReturned", do_numberOfRecordsReturned },
    { 0, "present",                 do_present },
    { 0, "type",                    do_type },
    { 0, "getMarc",                 do_getMarc },
    { 0, "getSutrs",                do_getSutrs },
    { 0, "getGrs",                  do_getGrs },
    { 0, "recordType",              do_recordType },
    { 0, "diag",                    do_diag },
    { 0, "responseStatus",          do_responseStatus },
    { 0, "loadFile",                do_loadFile },
    { 0, NULL, NULL}
};

/* 
 * ir_set_obj_method: IR Set Object methods
 */
static int ir_set_obj_method (ClientData clientData, Tcl_Interp *interp,
                          int argc, char **argv)
{
    IrTcl_Methods tabs[3];
    IrTcl_SetObj *p = clientData;

    if (argc < 2)
    {
        interp->result = "wrong # args";
        return TCL_ERROR;
    }
    tabs[0].tab = ir_set_method_tab;
    tabs[0].obj = p;
    tabs[1].tab = ir_set_c_method_tab;
    tabs[1].obj = &p->set_inher;
    tabs[2].tab = NULL;

    return ir_method (interp, argc, argv, tabs);
}

/* 
 * ir_set_obj_delete: IR Set Object disposal
 */
static void ir_set_obj_delete (ClientData clientData)
{
    IrTcl_Methods tabs[3];
    IrTcl_SetObj *p = clientData;

    logf (LOG_DEBUG, "ir set delete");

    tabs[0].tab = ir_set_method_tab;
    tabs[0].obj = p;
    tabs[1].tab = ir_set_c_method_tab;
    tabs[1].obj = &p->set_inher;
    tabs[2].tab = NULL;

    ir_method (NULL, -1, NULL, tabs);

    free (p);
}

/*
 * ir_set_obj_mk: IR Set Object creation
 */
static int ir_set_obj_mk (ClientData clientData, Tcl_Interp *interp,
                          int argc, char **argv)
{
    IrTcl_Methods tabs[3];
    IrTcl_SetObj *obj;

    if (argc < 2 || argc > 3)
    {
        interp->result = "wrong # args";
        return TCL_ERROR;
    }
    obj = ir_tcl_malloc (sizeof(*obj));
    logf (LOG_DEBUG, "ir set create");
    if (argc == 3)
    {
        Tcl_CmdInfo parent_info;
        int i;
        IrTcl_SetCObj *dst;
        IrTcl_SetCObj *src;

        if (!Tcl_GetCommandInfo (interp, argv[2], &parent_info))
        {
            interp->result = "No parent";
            return TCL_ERROR;
        }
        obj->parent = (IrTcl_Obj *) parent_info.clientData;

        dst = &obj->set_inher;
        src = &obj->parent->set_inher;

        if ((dst->num_databaseNames = src->num_databaseNames))
            dst->databaseNames =
                ir_tcl_malloc (sizeof (*dst->databaseNames)
                               * dst->num_databaseNames);
        else
            dst->databaseNames = NULL;
        for (i = 0; i < dst->num_databaseNames; i++)
            if (ir_tcl_strdup (interp, &dst->databaseNames[i],
                           src->databaseNames[i]) == TCL_ERROR)
                return TCL_ERROR;
        if (ir_tcl_strdup (interp, &dst->queryType, src->queryType)
            == TCL_ERROR)
            return TCL_ERROR;

        if (ir_tcl_strdup (interp, &dst->referenceId, src->referenceId)
            == TCL_ERROR)
            return TCL_ERROR;

        if (ir_tcl_strdup (interp, &dst->elementSetNames, src->elementSetNames)
            == TCL_ERROR)
            return TCL_ERROR;

        if (ir_tcl_strdup (interp, &dst->smallSetElementSetNames,
                           src->smallSetElementSetNames)
            == TCL_ERROR)
            return TCL_ERROR;

        if (ir_tcl_strdup (interp, &dst->mediumSetElementSetNames,
                           src->mediumSetElementSetNames)
            == TCL_ERROR)
            return TCL_ERROR;

        if (src->preferredRecordSyntax && 
            (dst->preferredRecordSyntax 
             = ir_tcl_malloc (sizeof(*dst->preferredRecordSyntax))))
            *dst->preferredRecordSyntax = *src->preferredRecordSyntax;
        else
            dst->preferredRecordSyntax = NULL;
        dst->replaceIndicator = src->replaceIndicator;
        dst->smallSetUpperBound = src->smallSetUpperBound;
        dst->largeSetLowerBound = src->largeSetLowerBound;
        dst->mediumSetPresentNumber = src->mediumSetPresentNumber;
    }   
    else
        obj->parent = NULL;

    tabs[0].tab = ir_set_method_tab;
    tabs[0].obj = obj;
    tabs[1].tab = NULL;

    if (ir_method (interp, 0, NULL, tabs) == TCL_ERROR)
        return TCL_ERROR;

    Tcl_CreateCommand (interp, argv[1], ir_set_obj_method,
                       (ClientData) obj, ir_set_obj_delete);
    return TCL_OK;
}

/* ------------------------------------------------------- */

/*
 * do_scan: Perform scan 
 */
static int do_scan (void *o, Tcl_Interp *interp, int argc, char **argv)
{
    Z_ScanRequest *req;
    Z_APDU *apdu;
    IrTcl_ScanObj *obj = o;
    IrTcl_Obj *p = obj->parent;
    oident bib1;
#if CCL2RPN
    struct ccl_rpn_node *rpn;
    int pos;
#endif

    if (argc <= 0)
        return TCL_OK;
    if (argc != 3)
    {
        interp->result = "wrong # args";
        return TCL_ERROR;
    }
    if (!p->set_inher.num_databaseNames)
    {
        interp->result = "no databaseNames";
	return TCL_ERROR;
    }
    if (!p->cs_link)
    {
        interp->result = "scan: not connected";
	return TCL_ERROR;
    }

    bib1.proto = p->protocol_type;
    bib1.class = CLASS_ATTSET;
    bib1.value = VAL_BIB1;

    apdu = zget_APDU (p->odr_out, Z_APDU_scanRequest);
    req = apdu->u.scanRequest;

    set_referenceId (p->odr_out, &req->referenceId, p->set_inher.referenceId);
    req->num_databaseNames = p->set_inher.num_databaseNames;
    req->databaseNames = p->set_inher.databaseNames;
    req->attributeSet = oid_getoidbyent (&bib1);

#if !CCL2RPN
    if (!(req->termListAndStartPoint = p_query_scan (p->odr_out, argv[2])))
    {
        Tcl_AppendResult (interp, "Syntax error in query", NULL);
	return TCL_ERROR;
    }
#else
    rpn = ccl_find_str(p->bibset, argv[2], &r, &pos);
    if (r)
    {
        Tcl_AppendResult (interp, "CCL error: ", ccl_err_msg (r), NULL);
        return TCL_ERROR;
    }
    ccl_pr_tree (rpn, stderr);
    fprintf (stderr, "\n");
    if (!(req->termListAndStartPoint = ccl_scan_query (rpn)))
        return TCL_ERROR;
#endif
    req->stepSize = &obj->stepSize;
    req->numberOfTermsRequested = &obj->numberOfTermsRequested;
    req->preferredPositionInResponse = &obj->preferredPositionInResponse;
    logf (LOG_DEBUG, "stepSize=%d", *req->stepSize);
    logf (LOG_DEBUG, "numberOfTermsRequested=%d",
          *req->numberOfTermsRequested);
    logf (LOG_DEBUG, "preferredPositionInResponse=%d",
          *req->preferredPositionInResponse);
    
    return ir_tcl_send_APDU (interp, p, apdu, "scan", argv[0]);
}

/*
 * do_stepSize: Set/get replace Step Size
 */
static int do_stepSize (void *obj, Tcl_Interp *interp,
                        int argc, char **argv)
{
    IrTcl_ScanObj *p = obj;
    if (argc <= 0)
    {
        p->stepSize = 0;
        return TCL_OK;
    }
    return get_set_int (&p->stepSize, interp, argc, argv);
}

/*
 * do_numberOfTermsRequested: Set/get Number of Terms requested
 */
static int do_numberOfTermsRequested (void *obj, Tcl_Interp *interp,
                                      int argc, char **argv)
{
    IrTcl_ScanObj *p = obj;

    if (argc <= 0)
    {
        p->numberOfTermsRequested = 20;
        return TCL_OK;
    }
    return get_set_int (&p->numberOfTermsRequested, interp, argc, argv);
}


/*
 * do_preferredPositionInResponse: Set/get preferred Position
 */
static int do_preferredPositionInResponse (void *obj, Tcl_Interp *interp,
                                           int argc, char **argv)
{
    IrTcl_ScanObj *p = obj;

    if (argc <= 0)
    {
        p->preferredPositionInResponse = 1;
        return TCL_OK;
    }
    return get_set_int (&p->preferredPositionInResponse, interp, argc, argv);
}

/*
 * do_scanStatus: Get scan status
 */
static int do_scanStatus (void *obj, Tcl_Interp *interp,
                          int argc, char **argv)
{
    IrTcl_ScanObj *p = obj;

    if (argc <= 0)
        return TCL_OK;
    return get_set_int (&p->scanStatus, interp, argc, argv);
}

/*
 * do_numberOfEntriesReturned: Get number of Entries returned
 */
static int do_numberOfEntriesReturned (void *obj, Tcl_Interp *interp,
                                       int argc, char **argv)
{
    IrTcl_ScanObj *p = obj;

    if (argc <= 0)
        return TCL_OK;
    return get_set_int (&p->numberOfEntriesReturned, interp, argc, argv);
}

/*
 * do_positionOfTerm: Get position of Term
 */
static int do_positionOfTerm (void *obj, Tcl_Interp *interp,
                              int argc, char **argv)
{
    IrTcl_ScanObj *p = obj;

    if (argc <= 0)
        return TCL_OK;
    return get_set_int (&p->positionOfTerm, interp, argc, argv);
}

/*
 * do_scanLine: get Scan Line (surrogate or normal) after response
 */
static int do_scanLine (void *obj, Tcl_Interp *interp, int argc, char **argv)
{
    IrTcl_ScanObj *p = obj;
    int i;
    char numstr[20];

    if (argc == 0)
    {
        p->entries_flag = 0;
	p->entries = NULL;
	p->nonSurrogateDiagnosticNum = 0;
        p->nonSurrogateDiagnosticList = 0;
	return TCL_OK;
    }
    else if (argc == -1)
    {
        p->entries_flag = 0;
	/* release entries */
        p->entries = NULL;

        ir_deleteDiags (&p->nonSurrogateDiagnosticList, 
                        &p->nonSurrogateDiagnosticNum);
	return TCL_OK;
    }
    if (argc != 3)
    {
        interp->result = "wrong # args";
	return TCL_ERROR;
    }
    if (Tcl_GetInt (interp, argv[2], &i) == TCL_ERROR)
        return TCL_ERROR;
    if (!p->entries_flag || p->which != Z_ListEntries_entries || !p->entries
        || i >= p->num_entries || i < 0)
        return TCL_OK;
    switch (p->entries[i].which)
    {
    case Z_Entry_termInfo:
        Tcl_AppendElement (interp, "T");
	if (p->entries[i].u.term.buf)
	    Tcl_AppendElement (interp, p->entries[i].u.term.buf);
	else
	    Tcl_AppendElement (interp, "");
	sprintf (numstr, "%d", p->entries[i].u.term.globalOccurrences);
	Tcl_AppendElement (interp, numstr);
	break;
    case Z_Entry_surrogateDiagnostic:
        Tcl_AppendElement (interp, "SD");
        return ir_diagResult (interp, p->entries[i].u.diag.list,
                              p->entries[i].u.diag.num);
	break;
    }
    return TCL_OK;
}

static IrTcl_Method ir_scan_method_tab[] = {
    { 0, "scan",                    do_scan },
    { 0, "stepSize",                do_stepSize },
    { 0, "numberOfTermsRequested",  do_numberOfTermsRequested },
    { 0, "preferredPositionInResponse", do_preferredPositionInResponse },
    { 0, "scanStatus",              do_scanStatus },
    { 0, "numberOfEntriesReturned", do_numberOfEntriesReturned },
    { 0, "positionOfTerm",          do_positionOfTerm },
    { 0, "scanLine",                do_scanLine },
    { 0, NULL, NULL}
};

/* 
 * ir_scan_obj_method: IR Scan Object methods
 */
static int ir_scan_obj_method (ClientData clientData, Tcl_Interp *interp,
                               int argc, char **argv)
{
    IrTcl_Methods tabs[2];

    if (argc < 2)
    {
        interp->result = "wrong # args";
        return TCL_ERROR;
    }
    tabs[0].tab = ir_scan_method_tab;
    tabs[0].obj = clientData;
    tabs[1].tab = NULL;

    return ir_method (interp, argc, argv, tabs);
}

/* 
 * ir_scan_obj_delete: IR Scan Object disposal
 */
static void ir_scan_obj_delete (ClientData clientData)
{
    IrTcl_Methods tabs[2];
    IrTcl_ScanObj *obj = clientData;

    tabs[0].tab = ir_scan_method_tab;
    tabs[0].obj = obj;
    tabs[1].tab = NULL;

    ir_method (NULL, -1, NULL, tabs);
    free (obj);
}

/* 
 * ir_scan_obj_mk: IR Scan Object creation
 */
static int ir_scan_obj_mk (ClientData clientData, Tcl_Interp *interp,
                           int argc, char **argv)
{
    Tcl_CmdInfo parent_info;
    IrTcl_ScanObj *obj;
    IrTcl_Methods tabs[2];

    if (argc != 3)
    {
        interp->result = "wrong # args";
        return TCL_ERROR;
    }
    if (!Tcl_GetCommandInfo (interp, argv[2], &parent_info))
    {
        interp->result = "No parent";
	return TCL_ERROR;
    }
    obj = ir_tcl_malloc (sizeof(*obj));
    obj->parent = (IrTcl_Obj *) parent_info.clientData;

    tabs[0].tab = ir_scan_method_tab;
    tabs[0].obj = obj;
    tabs[1].tab = NULL;

    if (ir_method (interp, 0, NULL, tabs) == TCL_ERROR)
        return TCL_ERROR;
    Tcl_CreateCommand (interp, argv[1], ir_scan_obj_method,
                       (ClientData) obj, ir_scan_obj_delete);
    return TCL_OK;
}

/* ------------------------------------------------------- */

static void ir_initResponse (void *obj, Z_InitResponse *initrs)
{
    IrTcl_Obj *p = obj;

    p->initResult = *initrs->result ? 1 : 0;
    if (!*initrs->result)
        logf (LOG_DEBUG, "Connection rejected by target");
    else
        logf (LOG_DEBUG, "Connection accepted by target");

    get_referenceId (&p->set_inher.referenceId, initrs->referenceId);

    free (p->targetImplementationId);
    ir_tcl_strdup (p->interp, &p->targetImplementationId,
               initrs->implementationId);
    free (p->targetImplementationName);
    ir_tcl_strdup (p->interp, &p->targetImplementationName,
               initrs->implementationName);
    free (p->targetImplementationVersion);
    ir_tcl_strdup (p->interp, &p->targetImplementationVersion,
               initrs->implementationVersion);

    p->maximumRecordSize = *initrs->maximumRecordSize;
    p->preferredMessageSize = *initrs->preferredMessageSize;
    
    memcpy (&p->options, initrs->options, sizeof(initrs->options));
    memcpy (&p->protocolVersion, initrs->protocolVersion,
            sizeof(initrs->protocolVersion));
    free (p->userInformationField);
    p->userInformationField = NULL;
    if (initrs->userInformationField)
    {
        int len;

        if (initrs->userInformationField->which == ODR_EXTERNAL_octet && 
            (p->userInformationField =
             ir_tcl_malloc ((len = 
                             initrs->userInformationField->
                             u.octet_aligned->len) +1)))
        {
            memcpy (p->userInformationField,
                    initrs->userInformationField->u.octet_aligned->buf,
                        len);
            (p->userInformationField)[len] = '\0';
        }
    }
}

static void ir_deleteDiags (IrTcl_Diagnostic **dst_list, int *dst_num)
{
    int i;
    for (i = 0; i<*dst_num; i++)
        free (dst_list[i]->addinfo);
    free (*dst_list);
    *dst_list = NULL;
    *dst_num = 0;
}

static void ir_handleDiags (IrTcl_Diagnostic **dst_list, int *dst_num,
                    Z_DiagRec **list, int num)
{
    int i;
    char *addinfo;

    *dst_num = num;
    *dst_list = ir_tcl_malloc (sizeof(**dst_list) * num);
    for (i = 0; i<num; i++)
    {
        switch (list[i]->which)
        {
        case Z_DiagRec_defaultFormat:
            (*dst_list)[i].condition = *list[i]->u.defaultFormat->condition;
            addinfo = list[i]->u.defaultFormat->addinfo;
            if (addinfo && 
                ((*dst_list)[i].addinfo = ir_tcl_malloc (strlen(addinfo)+1)))
                strcpy ((*dst_list)[i].addinfo, addinfo);
            break;
        default:
            (*dst_list)[i].addinfo = NULL;
            (*dst_list)[i].condition = 0;
        }
    }
}

static void ir_handleRecords (void *o, Z_Records *zrs, IrTcl_SetObj *setobj)
{
    IrTcl_Obj *p = o;

    int offset;
    IrTcl_RecordList *rl;

    setobj->which = zrs->which;
    setobj->recordFlag = 1;
    
    ir_deleteDiags (&setobj->nonSurrogateDiagnosticList,
                    &setobj->nonSurrogateDiagnosticNum);
    if (zrs->which == Z_Records_DBOSD)
    {
        setobj->numberOfRecordsReturned = 
            zrs->u.databaseOrSurDiagnostics->num_records;
        logf (LOG_DEBUG, "Got %d records", setobj->numberOfRecordsReturned);
        for (offset = 0; offset<setobj->numberOfRecordsReturned; offset++)
        {
            rl = new_IR_record (setobj, setobj->start + offset,
                                zrs->u.databaseOrSurDiagnostics->
                                records[offset]->which);
            if (rl->which == Z_NamePlusRecord_surrogateDiagnostic)
            {
                ir_handleDiags (&rl->u.surrogateDiagnostics.list,
                                &rl->u.surrogateDiagnostics.num,
                                &zrs->u.databaseOrSurDiagnostics->
                                records[offset]->u.surrogateDiagnostic,
                                1);
            } 
            else
            {
                Z_DatabaseRecord *zr; 
                Z_External *oe;
                struct oident *ident;
                
                zr = zrs->u.databaseOrSurDiagnostics->records[offset]
                    ->u.databaseRecord;
                oe = (Z_External*) zr;
		rl->u.dbrec.size = zr->u.octet_aligned->len;

                if ((ident = oid_getentbyoid (oe->direct_reference)))
                    rl->u.dbrec.type = ident->value;
                else
                    rl->u.dbrec.type = VAL_USMARC;

                if (oe->which == ODR_EXTERNAL_octet && rl->u.dbrec.size > 0)
                {
                    char *buf = (char*) zr->u.octet_aligned->buf;
                    if ((rl->u.dbrec.buf = ir_tcl_malloc (rl->u.dbrec.size)))
		        memcpy (rl->u.dbrec.buf, buf, rl->u.dbrec.size);
                }
                else if (rl->u.dbrec.type == VAL_SUTRS && 
                         oe->which == Z_External_sutrs)
                {
                    odr_setbuf (p->odr_in, (char*) oe->u.single_ASN1_type->buf,
                                oe->u.single_ASN1_type->len, 0);
                    if ((rl->u.dbrec.buf = ir_tcl_malloc (oe->u.sutrs->len+1)))
                    {
                        memcpy (rl->u.dbrec.buf, oe->u.sutrs->buf,
                                oe->u.sutrs->len);
                        rl->u.dbrec.buf[oe->u.sutrs->len] = '\0';
                    }
                    rl->u.dbrec.size = oe->u.sutrs->len;
                }
                else if (rl->u.dbrec.type == VAL_GRS1 && 
                         oe->which == Z_External_grs1)
                {
                    ir_tcl_read_grs (oe->u.grs1, &rl->u.dbrec.u.grs1);
                    rl->u.dbrec.buf = NULL;
                }
                else
                    rl->u.dbrec.buf = NULL;
            }
        }
    }
    else if (zrs->which == Z_Records_multipleNSD)
    {
        logf (LOG_DEBUG, "multipleNonSurrogateDiagnostic %d",
              zrs->u.multipleNonSurDiagnostics->num_diagRecs);
        setobj->numberOfRecordsReturned = 0;
        ir_handleDiags (&setobj->nonSurrogateDiagnosticList,
                        &setobj->nonSurrogateDiagnosticNum,
                        zrs->u.multipleNonSurDiagnostics->diagRecs,
                        zrs->u.multipleNonSurDiagnostics->num_diagRecs);
    }
    else
    {
        logf (LOG_DEBUG, "NonSurrogateDiagnostic");
        setobj->numberOfRecordsReturned = 0;
        ir_handleDiags (&setobj->nonSurrogateDiagnosticList,
                        &setobj->nonSurrogateDiagnosticNum,
                        &zrs->u.nonSurrogateDiagnostic,
                        1);
    }
}

static void ir_searchResponse (void *o, Z_SearchResponse *searchrs,
                               IrTcl_SetObj *setobj)
{    
    Z_Records *zrs = searchrs->records;

    logf (LOG_DEBUG, "Received search response");
    if (!setobj)
    {
        logf (LOG_DEBUG, "Search response, no object!");
	return;
    }
    setobj->searchStatus = searchrs->searchStatus ? 1 : 0;
    get_referenceId (&setobj->set_inher.referenceId, searchrs->referenceId);
    setobj->resultCount = *searchrs->resultCount;
    if (searchrs->presentStatus)
        setobj->presentStatus = *searchrs->presentStatus;
    if (searchrs->nextResultSetPosition)
        setobj->nextResultSetPosition = *searchrs->nextResultSetPosition;

    logf (LOG_DEBUG, "Search response %d, %d hits", 
          setobj->searchStatus, setobj->resultCount);
    if (zrs)
        ir_handleRecords (o, zrs, setobj);
    else
        setobj->recordFlag = 0;
}


static void ir_presentResponse (void *o, Z_PresentResponse *presrs,
                                IrTcl_SetObj *setobj)
{
    Z_Records *zrs = presrs->records;
    
    logf (LOG_DEBUG, "Received present response");
    if (!setobj)
    {
        logf (LOG_DEBUG, "Present response, no object!");
	return;
    }
    setobj->presentStatus = *presrs->presentStatus;
    get_referenceId (&setobj->set_inher.referenceId, presrs->referenceId);
    setobj->nextResultSetPosition = *presrs->nextResultSetPosition;
    if (zrs)
        ir_handleRecords (o, zrs, setobj);
    else
    {
        setobj->recordFlag = 0;
        logf (LOG_DEBUG, "No records!");
    }
}

static void ir_scanResponse (void *o, Z_ScanResponse *scanrs,
                             IrTcl_ScanObj *scanobj)
{
    IrTcl_Obj *p = o;
    
    logf (LOG_DEBUG, "Received scanResponse");

    get_referenceId (&p->set_inher.referenceId, scanrs->referenceId);
    scanobj->scanStatus = *scanrs->scanStatus;
    logf (LOG_DEBUG, "scanStatus=%d", scanobj->scanStatus);

    if (scanrs->stepSize)
        scanobj->stepSize = *scanrs->stepSize;
    logf (LOG_DEBUG, "stepSize=%d", scanobj->stepSize);

    scanobj->numberOfEntriesReturned = *scanrs->numberOfEntriesReturned;
    logf (LOG_DEBUG, "numberOfEntriesReturned=%d",
          scanobj->numberOfEntriesReturned);

    if (scanrs->positionOfTerm)
        scanobj->positionOfTerm = *scanrs->positionOfTerm;
    else
        scanobj->positionOfTerm = -1;
    logf (LOG_DEBUG, "positionOfTerm=%d", scanobj->positionOfTerm);

    free (scanobj->entries);
    scanobj->entries = NULL;

    ir_deleteDiags (&scanobj->nonSurrogateDiagnosticList,
                    &scanobj->nonSurrogateDiagnosticNum);
    if (scanrs->entries)
    {
        int i;
	Z_Entry *ze;

        scanobj->entries_flag = 1;
        scanobj->which = scanrs->entries->which;
	switch (scanobj->which)
	{
	case Z_ListEntries_entries:
	    scanobj->num_entries = scanrs->entries->u.entries->num_entries;
	    scanobj->entries = ir_tcl_malloc (scanobj->num_entries * 
	                               sizeof(*scanobj->entries));
            for (i=0; i<scanobj->num_entries; i++)
	    {
	        ze = scanrs->entries->u.entries->entries[i];
                scanobj->entries[i].which = ze->which;
		switch (ze->which)
		{
		case Z_Entry_termInfo:
		    if (ze->u.termInfo->term->which == Z_Term_general)
		    {
                        int l = ze->u.termInfo->term->u.general->len;
                        scanobj->entries[i].u.term.buf = ir_tcl_malloc (1+l);
			memcpy (scanobj->entries[i].u.term.buf, 
			        ze->u.termInfo->term->u.general->buf,
                                l);
                        scanobj->entries[i].u.term.buf[l] = '\0';
		    }
		    else
                        scanobj->entries[i].u.term.buf = NULL;
		    if (ze->u.termInfo->globalOccurrences)
		        scanobj->entries[i].u.term.globalOccurrences = 
		            *ze->u.termInfo->globalOccurrences;
		    else
		        scanobj->entries[i].u.term.globalOccurrences = 0;
                    break;
		case Z_Entry_surrogateDiagnostic:
                    ir_handleDiags (&scanobj->entries[i].u.diag.list,
                                    &scanobj->entries[i].u.diag.num,
                                    &ze->u.surrogateDiagnostic,
                                    1);
		    break;
		}
	    }
            break;
	case Z_ListEntries_nonSurrogateDiagnostics:
            ir_handleDiags (&scanobj->nonSurrogateDiagnosticList,
                            &scanobj->nonSurrogateDiagnosticNum,
                            scanrs->entries->u.nonSurrogateDiagnostics->
                            diagRecs,
                            scanrs->entries->u.nonSurrogateDiagnostics->
                            num_diagRecs);
            break;
	}
    }
    else
        scanobj->entries_flag = 0;
}

/*
 * ir_select_read: handle incoming packages
 */
void ir_select_read (ClientData clientData)
{
    IrTcl_Obj *p = clientData;
    Z_APDU *apdu;
    int r;
    IrTcl_Request *rq;
    char *object_name;
    Tcl_CmdInfo cmd_info;

    if (p->state == IR_TCL_R_Connecting)
    {
        r = cs_rcvconnect (p->cs_link);
        if (r == 1)
        {
            logf (LOG_WARN, "cs_rcvconnect returned 1");
            return;
        }
        p->state = IR_TCL_R_Idle;
        ir_select_remove_write (cs_fileno (p->cs_link), p);
        if (r < 0)
        {
            logf (LOG_DEBUG, "cs_rcvconnect error");
            if (p->failback)
            {
                p->failInfo = IR_TCL_FAIL_CONNECT;
                IrTcl_eval (p->interp, p->failback);
            }
            do_disconnect (p, NULL, 2, NULL);
            return;
        }
        p->state = IR_TCL_R_Idle;
        if (p->callback)
	    IrTcl_eval (p->interp, p->callback);
        if (p->cs_link && p->request_queue && p->state == IR_TCL_R_Idle)
            ir_tcl_send_q (p, p->request_queue, "x");
        return;
    }
    do
    {
	/* signal one more use of ir object - callbacks must not
	   release the ir memory (p pointer) */
        p->state = IR_TCL_R_Reading;
	++(p->ref_count);

        /* read incoming APDU */
        if ((r=cs_get (p->cs_link, &p->buf_in, &p->len_in)) <= 0)
        {
            logf (LOG_DEBUG, "cs_get failed, code %d", r);
            ir_select_remove (cs_fileno (p->cs_link), p);
            do_disconnect (p, NULL, 2, NULL);
            if (p->failback)
            {
                p->failInfo = IR_TCL_FAIL_READ;
                IrTcl_eval (p->interp, p->failback);
            }
	    /* release ir object now if callback deleted it */
	    ir_obj_delete (p);
            return;
        }        
        if (r == 1)
            return ;
        /* got complete APDU. Now decode */
        odr_setbuf (p->odr_in, p->buf_in, r, 0);
        logf (LOG_DEBUG, "cs_get ok, got %d", r);
        if (!z_APDU (p->odr_in, &apdu, 0))
        {
            logf (LOG_DEBUG, "%s", odr_errlist [odr_geterror (p->odr_in)]);
            do_disconnect (p, NULL, 2, NULL);
            if (p->failback)
            {
                p->failInfo = IR_TCL_FAIL_IN_APDU;
                IrTcl_eval (p->interp, p->failback);
            }
	    /* release ir object now if failback deleted it */
	    ir_obj_delete (p);
            return;
        }
        /* handle APDU and invoke callback */
        rq = p->request_queue;
        if (!rq)
        {
            logf (LOG_FATAL, "Internal error. No queue entry");
            exit (1);
        }
        object_name = rq->object_name;
        logf (LOG_DEBUG, "getCommandInfo (%s)", object_name);
        if (Tcl_GetCommandInfo (p->interp, object_name, &cmd_info))
        {
            switch(apdu->which)
            {
            case Z_APDU_initResponse:
                ir_initResponse (p, apdu->u.initResponse);
                break;
            case Z_APDU_searchResponse:
                ir_searchResponse (p, apdu->u.searchResponse,
                                   (IrTcl_SetObj *) cmd_info.clientData);
                break;
            case Z_APDU_presentResponse:
                ir_presentResponse (p, apdu->u.presentResponse,
                                    (IrTcl_SetObj *) cmd_info.clientData);
                break;
            case Z_APDU_scanResponse:
                ir_scanResponse (p, apdu->u.scanResponse, 
                                 (IrTcl_ScanObj *) cmd_info.clientData);
                break;
            default:
                logf (LOG_WARN, "Received unknown APDU type (%d)",
                      apdu->which);
                do_disconnect (p, NULL, 2, NULL);
                if (p->failback)
                {
                    p->failInfo = IR_TCL_FAIL_UNKNOWN_APDU;
                    IrTcl_eval (p->interp, p->failback);
                }
                return;
            }
        }
        p->request_queue = rq->next;
        p->state = IR_TCL_R_Idle;
        
        if (rq->callback)
            IrTcl_eval (p->interp, rq->callback);
        free (rq->buf_out);
        free (rq->callback);
        free (rq->object_name);
        free (rq);
        odr_reset (p->odr_in);
	if (p->ref_count == 1)
	{
	    ir_obj_delete (p);
	    return;
	}
	--(p->ref_count);
    } while (p->cs_link && cs_more (p->cs_link));
    if (p->cs_link && p->request_queue && p->state == IR_TCL_R_Idle)
        ir_tcl_send_q (p, p->request_queue, "x");
}

/*
 * ir_select_write: handle outgoing packages - not yet written.
 */
void ir_select_write (ClientData clientData)
{
    IrTcl_Obj *p = clientData;
    int r;
    IrTcl_Request *rq;

    logf (LOG_DEBUG, "In write handler");
    if (p->state == IR_TCL_R_Connecting)
    {
        r = cs_rcvconnect (p->cs_link);
        if (r == 1)
            return;
        p->state = IR_TCL_R_Idle;
        if (r < 0)
        {
            logf (LOG_DEBUG, "cs_rcvconnect error");
            ir_select_remove_write (cs_fileno (p->cs_link), p);
            if (p->failback)
            {
                p->failInfo = IR_TCL_FAIL_CONNECT;
                IrTcl_eval (p->interp, p->failback);
            }
            do_disconnect (p, NULL, 2, NULL);
            return;
        }
        ir_select_remove_write (cs_fileno (p->cs_link), p);
        if (p->callback)
	    IrTcl_eval (p->interp, p->callback);
        return;
    }
    rq = p->request_queue;
    assert (rq);
    if ((r=cs_put (p->cs_link, rq->buf_out, rq->len_out)) < 0)
    {
        logf (LOG_DEBUG, "select write fail");
        if (p->failback)
        {
            p->failInfo = IR_TCL_FAIL_WRITE;
            IrTcl_eval (p->interp, p->failback);
        }
        free (rq->buf_out);
        rq->buf_out = NULL;
        do_disconnect (p, NULL, 2, NULL);
    }
    else if (r == 0)            /* remove select bit */
    {
        p->state = IR_TCL_R_Waiting;
        ir_select_remove_write (cs_fileno (p->cs_link), p);
        free (rq->buf_out);
        rq->buf_out = NULL;
    }
}

/* ------------------------------------------------------- */

/*
 * Irtcl_init: Registration of TCL commands.
 */
int Irtcl_Init (Tcl_Interp *interp)
{
    Tcl_CreateCommand (interp, "ir", ir_obj_mk, (ClientData) NULL,
                       (Tcl_CmdDeleteProc *) NULL);
    Tcl_CreateCommand (interp, "ir-set", ir_set_obj_mk,
    		       (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
    Tcl_CreateCommand (interp, "ir-scan", ir_scan_obj_mk,
    		       (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
    return TCL_OK;
}

