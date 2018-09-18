Shared Libraries
================

## triponeconsensus

The purpose of this library is to make the verification functionality that is critical to Tripone's consensus available to other applications, e.g. to language bindings.

### API

The interface is defined in the C header `triponeconsensus.h` located in  `src/script/triponeconsensus.h`.

#### Version

`triponeconsensus_version` returns an `unsigned int` with the the API version *(currently at an experimental `0`)*.

#### Script Validation

`triponeconsensus_verify_script` returns an `int` with the status of the verification. It will be `1` if the input script correctly spends the previous output `scriptPubKey`.

##### Parameters
- `const unsigned char *scriptPubKey` - The previous output script that encumbers spending.
- `unsigned int scriptPubKeyLen` - The number of bytes for the `scriptPubKey`.
- `const unsigned char *txTo` - The transaction with the input that is spending the previous output.
- `unsigned int txToLen` - The number of bytes for the `txTo`.
- `unsigned int nIn` - The index of the input in `txTo` that spends the `scriptPubKey`.
- `unsigned int flags` - The script validation flags *(see below)*.
- `triponeconsensus_error* err` - Will have the error/success code for the operation *(see below)*.

##### Script Flags
- `triponeconsensus_SCRIPT_FLAGS_VERIFY_NONE`
- `triponeconsensus_SCRIPT_FLAGS_VERIFY_P2SH` - Evaluate P2SH ([BIP16](https://github.com/tripone/bips/blob/master/bip-0016.mediawiki)) subscripts
- `triponeconsensus_SCRIPT_FLAGS_VERIFY_DERSIG` - Enforce strict DER ([BIP66](https://github.com/tripone/bips/blob/master/bip-0066.mediawiki)) compliance

##### Errors
- `triponeconsensus_ERR_OK` - No errors with input parameters *(see the return value of `triponeconsensus_verify_script` for the verification status)*
- `triponeconsensus_ERR_TX_INDEX` - An invalid index for `txTo`
- `triponeconsensus_ERR_TX_SIZE_MISMATCH` - `txToLen` did not match with the size of `txTo`
- `triponeconsensus_ERR_DESERIALIZE` - An error deserializing `txTo`

### Example Implementations
- [NTripone](https://github.com/NicolasDorier/NTripone/blob/master/NTripone/Script.cs#L814) (.NET Bindings)
- [node-libtriponeconsensus](https://github.com/bitpay/node-libtriponeconsensus) (Node.js Bindings)
- [java-libtriponeconsensus](https://github.com/dexX7/java-libtriponeconsensus) (Java Bindings)
- [triponeconsensus-php](https://github.com/Bit-Wasp/triponeconsensus-php) (PHP Bindings)
