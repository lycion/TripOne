# Copyright (c) 2013-2016 The Bitcoin Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.

DIST_SUBDIRS = secp256k1 univalue

AM_LDFLAGS = $(PTHREAD_CFLAGS) $(LIBTOOL_LDFLAGS) $(HARDENED_LDFLAGS)
if ENABLE_GPERF
AM_CXXFLAGS = -fno-builtin-malloc -fno-builtin-calloc -fno-builtin-realloc -fno-builtin-free $(HARDENED_CXXFLAGS)
AM_CPPFLAGS = -fno-builtin-malloc -fno-builtin-calloc -fno-builtin-realloc -fno-builtin-free $(HARDENED_CPPFLAGS)
else
AM_CXXFLAGS = $(HARDENED_CXXFLAGS) $(ERROR_CXXFLAGS)
AM_CPPFLAGS = $(HARDENED_CPPFLAGS)
endif
if ENABLE_GPERF
AM_CXXFLAGS += -pg
AM_CPPFLAGS += -pg
AM_LDFLAGS  += -pg
endif
if ENABLE_GPROF
AM_CXXFLAGS += -pg
AM_CPPFLAGS += -pg
AM_LDFLAGS  += -pg
endif
if ENABLE_MUTRACE
AM_CXXFLAGS += -O0 -g -rdynamic
AM_CPPFLAGS += -O0 -g -rdynamic
AM_LDFLAGS  += -O0 -g -rdynamic
endif
EXTRA_LIBRARIES =
# litonemalloc.a

TRIPONE_CONFIG_INCLUDES=-I$(builddir)/config
TRIPONE_INCLUDES=-I$(builddir) -I$(builddir)/obj $(BDB_CPPFLAGS) $(BOOST_CPPFLAGS) $(LEVELDB_CPPFLAGS) $(CRYPTO_CFLAGS) $(SSL_CFLAGS)

TRIPONE_INCLUDES += -I$(srcdir)/secp256k1/include
TRIPONE_INCLUDES += -I$(srcdir)/univalue/include

LIBTRIPONE_SERVER=libtripone_server.a
LIBTRIPONE_COMMON=libtripone_common.a
LIBTRIPONE_CONSENSUS=libtripone_consensus.a
LIBTRIPONE_CLI=libtripone_cli.a
LIBTRIPONE_UTIL=libtripone_util.a
LIBTRIPONE_CRYPTO=crypto/libtripone_crypto.a
LIBTRIPONEQT=qt/libtriponeqt.a
LIBSECP256K1=secp256k1/libsecp256k1.la
LIBUNIVALUE=univalue/libunivalue.la

if ENABLE_ZMQ
LIBTRIPONE_ZMQ=libtripone_zmq.a
endif
if BUILD_TRIPONE_LIBS
LIBTRIPONECONSENSUS=libtriponeconsensus.la
LIBTRIPONECASH=libtriponecash.la
endif
if ENABLE_WALLET
LIBTRIPONE_WALLET=libtripone_wallet.a
endif

$(LIBSECP256K1): $(wildcard secp256k1/src/*) $(wildcard secp256k1/include/*)
	$(AM_V_at)$(MAKE) $(AM_MAKEFLAGS) -C $(@D) $(@F)

$(LIBUNIVALUE): $(wildcard univalue/lib/*) $(wildcard univalue/include/*)
	$(AM_V_at)$(MAKE) $(AM_MAKEFLAGS) -C $(@D) $(@F)

# Make is not made aware of per-object dependencies to avoid limiting building parallelization
# But to build the less dependent modules first, we manually select their order here:
EXTRA_LIBRARIES += \
  $(LIBTRIPONE_CRYPTO) \
  $(LIBTRIPONE_UTIL) \
  $(LIBTRIPONE_COMMON) \
  $(LIBTRIPONE_CONSENSUS) \
  $(LIBTRIPONE_SERVER) \
  $(LIBTRIPONE_CLI) \
  $(LIBTRIPONE_WALLET) \
  $(LIBTRIPONE_ZMQ)

lib_LTLIBRARIES = $(LIBTRIPONECASH) $(LIBTRIPONECONSENSUS)

bin_PROGRAMS =
noinst_PROGRAMS =
TESTS =
BENCHMARKS =

if BUILD_TRIPONED
  bin_PROGRAMS += triponed
endif

if BUILD_TRIPONE_UTILS
  bin_PROGRAMS += tripone-cli tripone-tx tripone-miner
endif

.PHONY: FORCE check-symbols check-security check-formatting
# tripone core #
TRIPONE_CORE_H = \
  addrman.h \
  allowed_args.h \
  base58.h \
  bandb.h \
  banentry.h \
  blockstorage/blockleveldb.h \
  blockstorage/sequential_files.h \
  blockstorage/blockstorage.h \
  bitnodes.h \
  bloom.h \
  cashaddr.h \
  cashaddrenc.h \
  chain.h \
  chainparams.h \
  chainparamsbase.h \
  chainparamsseeds.h \
  checkpoints.h \
  checkqueue.h \
  clientversion.h \
  coincontrol.h \
  coins.h \
  compat.h \
  compat/byteswap.h \
  compat/endian.h \
  compat/sanity.h \
  compressor.h \
  config.h \
  connmgr.h \
  consensus/consensus.h \
  consensus/tx_verify.h \
  core_io.h \
  core_memusage.h \
  dosman.h \
  dstencode.h \
  expedited.h \
  fast-cpp-csv-parser/csv.h \
  forks_csv.h \
  fs.h \
  graphene.h \
  graphene_set.h \
  httprpc.h \
  httpserver.h \
  iblt.h \
  iblt_params.h \
  init.h \
  key.h \
  keystore.h \
  dbwrapper.h \
  limitedmap.h \
  main.h \
  memusage.h \
  merkleblock.h \
  miner.h \
  net.h \
  nodestate.h \
  leakybucket.h \
  netaddress.h \
  netbase.h \
  noui.h \
  parallel.h \
  policy/fees.h \
  policy/policy.h \
  pow.h \
  protocol.h \
  random.h \
  reverselock.h \
  rpc/client.h \
  rpc/protocol.h \
  rpc/server.h \
  rpc/register.h \
  respend/respendaction.h \
  respend/respendlogger.h \
  respend/respendrelayer.h \
  respend/respenddetector.h \
  scheduler.h \
  script/sigcache.h \
  script/sign.h \
  script/standard.h \
  script/ismine.h \
  streams.h \
  support/allocators/secure.h \
  support/allocators/zeroafterfree.h \
  support/cleanse.h \
  support/pagelocker.h \
  sync.h \
  thinblock.h \
  threadsafety.h \
  timedata.h \
  torcontrol.h \
  txdb.h \
  txmempool.h \
  txorphanpool.h \
  ui_interface.h \
  uahf_fork.h \
  undo.h \
  unlimited.h \
  stat.h \
  tweak.h \
  requestManager.h \
  util.h \
  utilmoneystr.h \
  utiltime.h \
  validationinterface.h \
  versionbits.h \
  wallet/crypter.h \
  wallet/db.h \
  wallet/rpcwallet.h \
  wallet/wallet.h \
  wallet/walletdb.h \
  zmq/zmqabstractnotifier.h \
  zmq/zmqconfig.h\
  zmq/zmqnotificationinterface.h \
  zmq/zmqpublishnotifier.h


obj/build.h: FORCE
	@$(MKDIR_P) $(builddir)/obj
	@$(top_srcdir)/share/genbuild.sh $(abs_top_builddir)/src/obj/build.h \
	  $(abs_top_srcdir)
libtripone_util_a-clientversion.$(OBJEXT): obj/build.h

# server: shared between triponed and tripone-qt
libtripone_server_a_CPPFLAGS = $(AM_CPPFLAGS) $(TRIPONE_INCLUDES) $(MINIUPNPC_CPPFLAGS) $(EVENT_CFLAGS) $(EVENT_PTHREADS_CFLAGS)
libtripone_server_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libtripone_server_a_SOURCES = \
  globals.cpp \
  addrman.cpp \
  bandb.cpp \
  banentry.cpp \
  bitnodes.cpp \
  blockstorage/blockleveldb.cpp \
  blockstorage/sequential_files.cpp \
  blockstorage/blockstorage.cpp \
  bloom.cpp \
  chain.cpp \
  checkpoints.cpp \
  connmgr.cpp \
  consensus/tx_verify.cpp \
  dosman.cpp \
  expedited.cpp \
  forks_csv.cpp \
  graphene.cpp \
  httprpc.cpp \
  httpserver.cpp \
  iblt.cpp \
  init.cpp \
  dbwrapper.cpp \
  main.cpp \
  merkleblock.cpp \
  miner.cpp \
  net.cpp \
  nodestate.cpp \
  noui.cpp \
  parallel.cpp \
  policy/fees.cpp \
  policy/policy.cpp \
  pow.cpp \
  rest.cpp \
  rpc/blockchain.cpp \
  rpc/mining.cpp \
  rpc/misc.cpp \
  rpc/net.cpp \
  rpc/rawtransaction.cpp \
  rpc/server.cpp \
  respend/respendlogger.cpp \
  respend/respendrelayer.cpp \
  respend/respenddetector.cpp \
  script/sigcache.cpp \
  thinblock.cpp \
  script/ismine.cpp \
  timedata.cpp \
  torcontrol.cpp \
  txdb.cpp \
  txmempool.cpp \
  txorphanpool.cpp \
  tweak.cpp \
  uahf_fork.cpp \
  unlimited.cpp \
  requestManager.cpp \
  validationinterface.cpp \
  versionbits.cpp \
  $(TRIPONE_CORE_H)

if ENABLE_ZMQ
libtripone_zmq_a_CPPFLAGS = $(TRIPONE_INCLUDES) $(ZMQ_CFLAGS)
libtripone_zmq_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libtripone_zmq_a_SOURCES = \
  zmq/zmqabstractnotifier.cpp \
  zmq/zmqnotificationinterface.cpp \
  zmq/zmqpublishnotifier.cpp
endif


# wallet: shared between triponed and tripone-qt, but only linked
# when wallet enabled
libtripone_wallet_a_CPPFLAGS = $(AM_CPPFLAGS) $(TRIPONE_INCLUDES)
libtripone_wallet_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libtripone_wallet_a_SOURCES = \
  wallet/crypter.cpp \
  wallet/db.cpp \
  wallet/rpcdump.cpp \
  wallet/rpcwallet.cpp \
  wallet/wallet.cpp \
  wallet/walletdb.cpp \
  $(TRIPONE_CORE_H)

libtriponecash_a_CPPFLAGS = $(AM_CPPFLAGS) $(TRIPONE_INCLUDES)
libtriponecash_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)

# base58.cpp
#  base58.h

libtriponecash_a_SOURCES = \
  cashlib/cashlib.cpp \
  script/sigcommon.cpp \
  hash.cpp \
  hash.h \
  key.cpp \
  key.h \
  primitives/transaction.cpp \
  primitives/transaction.h \
  pubkey.cpp \
  pubkey.h \
  random.cpp \
  random.h \
  support/pagelocker.cpp \
  support/pagelocker.h \
  support/cleanse.cpp \
  support/cleanse.h \
  uint256.cpp \
  uint256.h \
  utilstrencodings.cpp \
  utilstrencodings.h \
  utiltime.cpp \
  utiltime.h

# crypto primitives library
crypto_libtripone_crypto_a_CPPFLAGS = $(AM_CPPFLAGS) $(TRIPONE_CONFIG_INCLUDES)
crypto_libtripone_crypto_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
crypto_libtripone_crypto_a_SOURCES = \
  crypto/aes.cpp \
  crypto/aes.h \
  crypto/common.h \
  crypto/hmac_sha256.cpp \
  crypto/hmac_sha256.h \
  crypto/hmac_sha512.cpp \
  crypto/hmac_sha512.h \
  crypto/ripemd160.cpp \
  crypto/ripemd160.h \
  crypto/sha1.cpp \
  crypto/sha1.h \
  crypto/sha256.cpp \
  crypto/sha256.h \
  crypto/sha512.cpp \
  crypto/sha512.h

if USE_ASM
crypto_libtripone_crypto_a_SOURCES += crypto/sha256_sse4.cpp
endif

# consensus: shared between all executables that validate any consensus rules.
libtripone_consensus_a_CPPFLAGS = $(AM_CPPFLAGS) $(TRIPONE_INCLUDES)
libtripone_consensus_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libtripone_consensus_a_SOURCES = \
  amount.h \
  arith_uint256.cpp \
  arith_uint256.h \
  consensus/merkle.cpp \
  consensus/merkle.h \
  consensus/params.h \
  consensus/validation.h \
  hash.cpp \
  hash.h \
  prevector.h \
  primitives/block.cpp \
  primitives/block.h \
  primitives/transaction.cpp \
  primitives/transaction.h \
  pubkey.cpp \
  pubkey.h \
  script/triponeconsensus.cpp \
  script/interpreter.cpp \
  script/interpreter.h \
  script/sigcommon.cpp \
  script/script.cpp \
  script/script.h \
  script/script_error.cpp \
  script/script_error.h \
  serialize.h \
  tinyformat.h \
  uint256.cpp \
  uint256.h \
  utilstrencodings.cpp \
  utilstrencodings.h \
  version.h

# common: shared between triponed, and tripone-qt and non-server tools
libtripone_common_a_CPPFLAGS = $(AM_CPPFLAGS) $(TRIPONE_INCLUDES)
libtripone_common_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libtripone_common_a_SOURCES = \
  amount.cpp \
  base58.cpp \
  cashaddr.cpp \
  cashaddrenc.cpp \
  chainparams.cpp \
  coins.cpp \
  compressor.cpp \
  config.cpp \
  core_read.cpp \
  core_write.cpp \
  dstencode.cpp \
  key.cpp \
  keystore.cpp \
  netaddress.cpp \
  netbase.cpp \
  protocol.cpp \
  scheduler.cpp \
  script/sign.cpp \
  script/standard.cpp \
  versionbits.cpp \
  chain.cpp \
  $(TRIPONE_CORE_H)

# util: shared between all executables.
# This library *must* be included to make sure that the glibc
# backward-compatibility objects and their sanity checks are linked.
libtripone_util_a_CPPFLAGS = $(AM_CPPFLAGS) $(TRIPONE_INCLUDES)
libtripone_util_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libtripone_util_a_SOURCES = \
  support/pagelocker.cpp \
  allowed_args.cpp \
  chainparamsbase.cpp \
  clientversion.cpp \
  compat/glibc_sanity.cpp \
  compat/glibcxx_sanity.cpp \
  compat/strnlen.cpp \
  fs.cpp \
  random.cpp \
  rpc/protocol.cpp \
  support/cleanse.cpp \
  sync.cpp \
  ui_interface.cpp \
  util.cpp \
  utilmoneystr.cpp \
  utilstrencodings.cpp \
  utiltime.cpp \
  $(TRIPONE_CORE_H)

if GLIBC_BACK_COMPAT
libtripone_util_a_SOURCES += compat/glibc_compat.cpp
endif

# cli: shared between tripone-cli and tripone-qt
libtripone_cli_a_CPPFLAGS = $(AM_CPPFLAGS) $(TRIPONE_INCLUDES) $(EVENT_CFLAGS)
libtripone_cli_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
libtripone_cli_a_SOURCES = \
  rpc/client.cpp \
  $(TRIPONE_CORE_H)

nodist_libtripone_util_a_SOURCES = $(srcdir)/obj/build.h
#

# triponed binary #
triponed_SOURCES = triponed.cpp
triponed_CPPFLAGS = $(AM_CPPFLAGS) $(TRIPONE_INCLUDES)
triponed_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
triponed_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS)

if TARGET_WINDOWS
triponed_SOURCES += triponed-res.rc
endif

triponed_LDADD = \
  $(LIBTRIPONE_SERVER) \
  $(LIBTRIPONE_COMMON) \
  $(LIBUNIVALUE) \
  $(LIBTRIPONE_UTIL) \
  $(LIBTRIPONE_WALLET) \
  $(LIBTRIPONE_ZMQ) \
  $(LIBTRIPONE_CONSENSUS) \
  $(LIBTRIPONE_CRYPTO) \
  $(LIBLEVELDB) \
  $(LIBLEVELDB_SSE42) \
  $(LIBMEMENV) \
  $(LIBSECP256K1)

triponed_LDADD += $(BOOST_LIBS) $(BDB_LIBS) $(SSL_LIBS) $(CRYPTO_LIBS) $(MINIUPNPC_LIBS) $(EVENT_PTHREADS_LIBS) $(EVENT_LIBS) $(ZMQ_LIBS)

# tripone-cli binary #
tripone_cli_SOURCES = tripone-cli.cpp
tripone_cli_CPPFLAGS = $(AM_CPPFLAGS) $(TRIPONE_INCLUDES) $(EVENT_CFLAGS)
tripone_cli_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
tripone_cli_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS)

if TARGET_WINDOWS
tripone_cli_SOURCES += tripone-cli-res.rc
endif

tripone_cli_LDADD = \
  $(LIBTRIPONE_CLI) \
  $(LIBUNIVALUE) \
  $(LIBTRIPONE_UTIL)

tripone_cli_LDADD += $(BOOST_LIBS) $(SSL_LIBS) $(CRYPTO_LIBS) $(EVENT_LIBS)
#

# tripone-tx binary #
tripone_tx_SOURCES = tripone-tx.cpp
tripone_tx_CPPFLAGS = $(AM_CPPFLAGS) $(TRIPONE_INCLUDES)
tripone_tx_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
tripone_tx_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS)

if TARGET_WINDOWS
tripone_tx_SOURCES += tripone-tx-res.rc
endif

tripone_tx_LDADD = \
  $(LIBUNIVALUE) \
  $(LIBTRIPONE_COMMON) \
  $(LIBTRIPONE_UTIL) \
  $(LIBTRIPONE_CONSENSUS) \
  $(LIBTRIPONE_CRYPTO) \
  $(LIBSECP256K1)

tripone_tx_LDADD += $(BOOST_LIBS) $(CRYPTO_LIBS)
#

# tripone-miner binary #
tripone_miner_SOURCES = tripone-miner.cpp \
  arith_uint256.cpp \
  arith_uint256.h \
  uint256.cpp \
  uint256.h


tripone_miner_CPPFLAGS = $(AM_CPPFLAGS) $(TRIPONE_INCLUDES) $(EVENT_CFLAGS)
tripone_miner_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
tripone_miner_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS)

if TARGET_WINDOWS
tripone_miner_SOURCES += tripone-miner-res.rc
endif

tripone_miner_LDADD = \
  $(LIBTRIPONE_CLI) \
  $(LIBTRIPONE_CRYPTO) \
  $(LIBUNIVALUE) \
  $(LIBTRIPONE_UTIL)

tripone_miner_LDADD += $(BOOST_LIBS) $(SSL_LIBS) $(CRYPTO_LIBS) $(EVENT_LIBS)
#

# triponecash library #
if BUILD_TRIPONE_LIBS
libtriponecash_la_SOURCES = $(libtriponecash_a_SOURCES) $(crypto_libtripone_crypto_a_SOURCES)

if GLIBC_BACK_COMPAT
  libtriponecash_la_SOURCES += compat/glibc_compat.cpp
endif

libtriponecash_la_LDFLAGS = $(AM_LDFLAGS) $(SSL_LIBS) $(CRYPTO_LIBS) $(BOOST_LIBS) -no-undefined $(RELDFLAGS)
libtriponecash_la_LIBADD = $(LIBSECP256K1)
libtriponecash_la_CPPFLAGS = $(AM_CPPFLAGS) -I$(BOOST_CPPFLAGS) -I$(builddir)/obj -I$(srcdir)/secp256k1/include -DBUILD_TRIPONE_INTERNAL
libtriponecash_la_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)

endif
#

# triponeconsensus library #
if BUILD_TRIPONE_LIBS
include_HEADERS = script/triponeconsensus.h
libtriponeconsensus_la_SOURCES = $(crypto_libtripone_crypto_a_SOURCES) $(libtripone_consensus_a_SOURCES)

if GLIBC_BACK_COMPAT
  libtriponeconsensus_la_SOURCES += compat/glibc_compat.cpp
endif

libtriponeconsensus_la_LDFLAGS = $(AM_LDFLAGS) $(BOOST_LIBS) -no-undefined $(RELDFLAGS)
libtriponeconsensus_la_LIBADD = $(LIBSECP256K1)
libtriponeconsensus_la_CPPFLAGS = $(AM_CPPFLAGS) -I$(BOOST_CPPFLAGS) -I$(builddir)/obj -I$(srcdir)/secp256k1/include -DBUILD_TRIPONE_INTERNAL
libtriponeconsensus_la_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)

endif
#
CLEANFILES = $(EXTRA_LIBRARIES)

CTAES_DIST =  crypto/ctaes/bench.c
CTAES_DIST += crypto/ctaes/ctaes.c
CTAES_DIST += crypto/ctaes/ctaes.h
CTAES_DIST += crypto/ctaes/README.md
CTAES_DIST += crypto/ctaes/test.c

CLEANFILES += *.gcda *.gcno
CLEANFILES += compat/*.gcda compat/*.gcno
CLEANFILES += consensus/*.gcda consensus/*.gcno
CLEANFILES += crypto/*.gcda crypto/*.gcno
CLEANFILES += policy/*.gcda policy/*.gcno
CLEANFILES += primitives/*.gcda primitives/*.gcno
CLEANFILES += script/*.gcda script/*.gcno
CLEANFILES += support/*.gcda support/*.gcno
CLEANFILES += univalue/*.gcda univalue/*.gcno
CLEANFILES += wallet/*.gcda wallet/*.gcno
CLEANFILES += wallet/test/*.gcda wallet/test/*.gcno
CLEANFILES += zmq/*.gcda zmq/*.gcno

DISTCLEANFILES = obj/build.h

EXTRA_DIST = leveldb $(CTAES_DIST)

clean-local:
	-$(MAKE) -C secp256k1 clean
	-$(MAKE) -C univalue clean
	-rm -f leveldb/*/*.gcda leveldb/*/*.gcno leveldb/helpers/memenv/*.gcda leveldb/helpers/memenv/*.gcno
	-rm -rf test/__pycache__

.rc.o:
	@test -f $(WINDRES)
	## FIXME: How to get the appropriate modulename_CPPFLAGS in here?
	$(AM_V_GEN) $(WINDRES) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(CPPFLAGS) -DWINDRES_PREPROC -i $< -o $@

.mm.o:
	$(AM_V_CXX) $(OBJCXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) \
	  $(CPPFLAGS) $(AM_CXXFLAGS) $(QT_INCLUDES) $(AM_CXXFLAGS) $(PIE_FLAGS) $(CXXFLAGS) -c -o $@ $<

check-symbols: $(bin_PROGRAMS)
if GLIBC_BACK_COMPAT
	@echo "Checking glibc back compat..."
	$(AM_V_at) READELF=$(READELF) CPPFILT=$(CPPFILT) $(top_srcdir)/contrib/devtools/symbol-check.py < $(bin_PROGRAMS)
endif

check-security: $(bin_PROGRAMS)
if HARDEN
	@echo "Checking binary security..."
	$(AM_V_at) READELF=$(READELF) OBJDUMP=$(OBJDUMP) $(top_srcdir)/contrib/devtools/security-check.py < $(bin_PROGRAMS)
endif

check-formatting:
	@echo "Checking source formatting style..."
	(cd $(top_srcdir)/src; ../contrib/devtools/clang-format.py check clang-format-3.8 `cat ./.formatted-files`)

%.pb.cc %.pb.h: %.proto
	@test -f $(PROTOC)
	$(AM_V_GEN) $(PROTOC) --cpp_out=$(@D) --proto_path=$(abspath $(<D) $<)

if EMBEDDED_LEVELDB
include Makefile.leveldb.include
endif

if ENABLE_TESTS
include Makefile.test.include
endif

if ENABLE_BENCH
include Makefile.bench.include
endif

if ENABLE_QT
include Makefile.qt.include
endif

if ENABLE_QT_TESTS
include Makefile.qttest.include
endif
