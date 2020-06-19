/**
 * PSec Internal Library
 */

type StringType;
type machine_handle;
type capability;
type secure_machine_handle;
type secure_StringType;
type sealed_data;
type sealed_data_key;

fun Declassify(input : any) : any;
fun Endorse(input : any) : any;

fun GetThis() : machine_handle;

fun CreateSecureMachineRequest(): secure_machine_handle;
fun CreateUSMMachineRequest(): machine_handle;

fun GenerateSealedDataKey() : sealed_data_key;
fun GenerateSealedData(input1:sealed_data_key, input2:any) : sealed_data;

fun seal(input : any) : (sealed_data_key, sealed_data) {
    var output: (sealed_data_key, sealed_data);
    output.0 = GenerateSealedDataKey();
    output.1 = GenerateSealedData(output.0, input);
    return output;
}

fun unseal(input1:sealed_data_key, input2:sealed_data) : any;

fun localAuthenticate(input1: machine_handle, input2: string) : bool;