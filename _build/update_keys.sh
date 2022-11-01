#!/bin/sh
gpg --armor --export --fingerprint 6DFBCB92DD55AA63B4159B4D78EE57144AC275FE > _keys/brip_master_key.pub
gpg --armor --export --fingerprint F7B9EA3E11ED5BC1BDFB57CBB33EBF057F0828E4 > _keys/brip_release_key.pub
gpg --armor --export --fingerprint D52C1548F4FD6D14A1049CB3C659B63CE8EA6FCA > _keys/brip_dev_key.pub
