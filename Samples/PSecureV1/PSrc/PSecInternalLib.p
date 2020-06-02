/**
 * PSec Internal Library
 */

type StringType;
type machine_handle;
type capability;
type secure_machine_handle;
type secure_StringType;

fun Declassify(input : any) : any;
fun Endorse(input : any) : any;

fun GetThis() : machine_handle;

fun CreateSecureMachineRequest(): secure_machine_handle;
fun CreateUSMMachineRequest(): machine_handle;