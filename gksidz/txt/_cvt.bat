@echo off

if exist txt___01.dbt del txt___01.dbt
if exist txt___02.dbt del txt___02.dbt
if exist txt___03.dbt del txt___03.dbt

if exist txt___01.txt vkdbfu txt___01.dbt c txt___01.txt r10
if exist txt___02.txt vkdbfu txt___02.dbt c txt___02.txt r10
if exist txt___03.txt vkdbfu txt___03.dbt c txt___03.txt r10
