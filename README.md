# CORONA VIRUS SMART CONTRACT

## Prerequisities

1. [Create Key](https://monitor.jungletestnet.io/#createKey)
2. [Create Account](https://monitor.jungletestnet.io/#account)
3. [Send Coins to Test DApp](https://monitor.jungletestnet.io/#faucet)
4. [Use Bloks.io](https://jungle.bloks.io)

### Buy RAM
192.251 Bytes RAM (10 EOS)

```
cleos -u https://api.jungle.alohaeos.com push transaction '{"delay_sec":0,"max_cpu_usage_ms":0,"actions":[{"account":"eosio","name":"buyrambytes","data":{"payer":"clementine34","receiver":"clementine34","bytes":175000},"authorization":[{"actor":"clementine34","permission":"active"}]}]}'
```

## Compile Smart Contract

```
eosio-cpp coronavirus.cpp 
```

## Create the wallet and save password 
```
cleos wallet create --to-console
```

Import private key

## Deploy and run smart contract on Jungle Test 
```
cleos -u https://jungle2.cryptolions.io:443 set contract <YOUR ACCOUNT> . -p <YOUR ACCOUNT>@active
```

### Run Action 

#### Send data 

```
cleos -u https://api.jungle.alohaeos.com push transaction '{"delay_sec":0,"max_cpu_usage_ms":0,"actions":[{"account":"<YOUR ACCOUNT>","name":"send","data":{"time_in_seconds":1582536345,"data_type":"covid-19","state":"IT","region_code":20,"region":"PUGLIA","prov_code":11,"prov":"BARI","prov_tag":"BA","lat":42.35103167,"lng":14.16754574,"ni":12,"source":"https://github.com/pcm-dpc/COVID-19/blob/master/dati-json/dpc-covid19-ita-province.json"},"authorization":[{"actor":"<YOUR ACCOUNT>","permission":"active"}]}]}'
```

#### Clear one record 
```
cleos -u https://api.jungle.alohaeos.com push transaction '{"delay_sec":0,"max_cpu_usage_ms":0,"actions":[{"account":"<YOUR ACCOUNT>","name":"clearone","data":{"id":0},"authorization":[{"actor":"<YOUR ACCOUNT>","permission":"active"}]}]}'
```

#### Clear all record 

```
cleos -u https://api.jungle.alohaeos.com push transaction '{"delay_sec":0,"max_cpu_usage_ms":0,"actions":[{"account":"clementine33","name":"clearall","data":{},"authorization":[{"actor":"clementine33","permission":"active"}]}]}'
```

### Get data 
```
cleos -u https://jungle2.cryptolions.io:443 get table <YOUR ACCOUNT> <YOUR ACCOUNT> infection 
```

