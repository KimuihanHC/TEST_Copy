�
 TCUSTOMERDATA 0�  TPF0TCustomerDataCustomerDataOldCreateOrder	Left� Top� Height� Width? TTable	CustomersDatabaseNameBCDEMOS	TableNameCUSTOMER.DBLeft Top TFloatFieldCustomersCustNo	FieldNameCustNo  TStringFieldCustomersCompany	FieldNameCompanySize  TStringFieldCustomersAddr1	FieldNameAddr1Size  TStringFieldCustomersAddr2	FieldNameAddr2Size  TStringFieldCustomersCity	FieldNameCitySize  TStringFieldCustomersState	FieldNameState  TStringFieldCustomersZip	FieldNameZipSize
  TStringFieldCustomersCountry	FieldNameCountry  TStringFieldCustomersPhone	FieldNamePhoneSize  TStringFieldCustomersFAX	FieldNameFAXSize  TFloatFieldCustomersTaxRate	FieldNameTaxRate  TStringFieldCustomersContact	FieldNameContact  TDateTimeFieldCustomersLastInvoiceDate	FieldNameLastInvoiceDate   TTableOrdersDatabaseNameBCDEMOS	TableName	ORDERS.DBLefthTop TFloatFieldOrdersOrderNo	FieldNameOrderNo  TFloatFieldOrdersCustNo	FieldNameCustNoRequired	  TStringFieldOrdersCustCompany	FieldKindfkLookup	FieldNameCustCompanyLookupDataSetCustomerLookupLookupKeyFieldsCustNoLookupResultFieldCompany	KeyFieldsCustNoLookup	  TDateTimeFieldOrdersSaleDate	FieldNameSaleDate  TDateTimeFieldOrdersShipDate	FieldNameShipDate  TIntegerFieldOrdersEmpNo	FieldNameEmpNoRequired	  TStringFieldOrdersShipToContact	FieldNameShipToContact  TStringFieldOrdersShipToAddr1	FieldNameShipToAddr1Size  TStringFieldOrdersShipToAddr2	FieldNameShipToAddr2Size  TStringFieldOrdersShipToCity	FieldName
ShipToCitySize  TStringFieldOrdersShipToState	FieldNameShipToState  TStringFieldOrdersShipToZip	FieldName	ShipToZipSize
  TStringFieldOrdersShipToCountry	FieldNameShipToCountry  TStringFieldOrdersShipToPhone	FieldNameShipToPhoneSize  TStringFieldOrdersShipVIA	FieldNameShipVIASize  TStringFieldOrdersPO	FieldNamePOSize  TStringFieldOrdersTerms	FieldNameTermsSize  TStringFieldOrdersPaymentMethod	FieldNamePaymentMethodSize  TCurrencyFieldOrdersItemsTotal	FieldName
ItemsTotal  TFloatFieldOrdersTaxRate	FieldNameTaxRate  TCurrencyFieldOrdersFreight	FieldNameFreight  TCurrencyFieldOrdersAmountPaid	FieldName
AmountPaid   TTable	LineItemsOnCalcFieldsLineItemsCalcFieldsDatabaseNameBCDEMOSIndexFieldNamesOrderNoMasterFieldsOrderNoMasterSourceOrderSource	TableNameITEMS.DBLeft� Top TFloatFieldLineItemsOrderNo	FieldNameOrderNoVisible  TFloatFieldLineItemsItemNo	FieldNameItemNo  TFloatFieldLineItemsPartNo	FieldNamePartNo  TStringFieldLineItemsPartName	FieldKindfkLookup	FieldNamePartNameLookupDataSet
PartLookupLookupKeyFieldsPartNoLookupResultFieldDescription	KeyFieldsPartNoLookup	  TIntegerFieldLineItemsQty	FieldNameQty  TCurrencyFieldLineItemsPrice	FieldKindfkLookup	FieldNamePriceLookupDataSet
PartLookupLookupKeyFieldsPartNoLookupResultField	ListPrice	KeyFieldsPartNoLookup	  TFloatFieldLineItemsDiscount	FieldNameDiscountDisplayFormat#0.#%
EditFormat##.#	Precision  TCurrencyFieldLineItemsExtendedPrice	FieldKindfkCalculated	FieldNameExtendedPrice
Calculated	  TCurrencyFieldLineItemsTotal	FieldKindfkCalculated	FieldNameTotal
Calculated	   TTablePartsDatabaseNameBCDEMOS	TableNamePARTS.DBLeft� Top TFloatFieldPartsPartNo	FieldNamePartNo  TFloatFieldPartsVendorNo	FieldNameVendorNo  TStringFieldPartsDescription	FieldNameDescriptionSize  TFloatFieldPartsOnHand	FieldNameOnHand  TFloatFieldPartsOnOrder	FieldNameOnOrder  TCurrencyField	PartsCost	FieldNameCost  TCurrencyFieldPartsListPrice	FieldName	ListPrice   TDataSourceCustomerSourceDataSet	CustomersLeft Top8  TDataSourceOrderSourceDataSetOrdersLefthTop8  TDataSourceLineItemSourceDataSet	LineItemsLeft� Top8  TDataSource
PartSourceDataSetPartsLeft� Top8  TTableCustomerLookupDatabaseNameBCDEMOS	TableNameCUSTOMER.DBLeft Toph TFloatFieldFloatField1	FieldNameCustNo  TStringFieldStringField1	FieldNameCompanySize  TStringFieldStringField2	FieldNameAddr1Size  TStringFieldStringField3	FieldNameAddr2Size  TStringFieldStringField4	FieldNameCitySize  TStringFieldStringField5	FieldNameState  TStringFieldStringField6	FieldNameZipSize
  TStringFieldStringField7	FieldNameCountry  TStringFieldStringField8	FieldNamePhoneSize  TStringFieldStringField9	FieldNameFAXSize  TFloatFieldFloatField2	FieldNameTaxRate  TStringFieldStringField10	FieldNameContact  TDateTimeFieldDateTimeField1	FieldNameLastInvoiceDate   TTable
PartLookupDatabaseNameBCDEMOS	TableNamePARTS.DBLeft� Toph TFloatFieldFloatField3	FieldNamePartNo  TFloatFieldFloatField4	FieldNameVendorNo  TStringFieldStringField11	FieldNameDescriptionSize  TFloatFieldFloatField5	FieldNameOnHand  TFloatFieldFloatField6	FieldNameOnOrder  TCurrencyFieldCurrencyField1	FieldNameCost  TCurrencyFieldCurrencyField2	FieldName	ListPrice    